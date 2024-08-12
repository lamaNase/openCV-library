
// Convert cv::Mat to QImage for display in QLabel
QImage matToQImage() {
    	cv::Mat rgb;
    	cv::cvtColor(combinedDisplay, rgb, cv::COLOR_BGR2RGB);
    	QImage qimage1(rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888);
	QImage image = qimage1.copy();
	//image.save("out.png");
	return image;
}

void updateFrames() {
    
    while (isRunning) {
        
        cv::Mat resizedFrame1, resizedFrame2, resizedFrame3, resizedFrame4;
        {
            std::unique_lock<std::mutex> lock(displayMutex);
            if (!display.empty()) {
        	cv::resize(display, resizedFrame1, cv::Size(width, height));
        	resizedFrame1.copyTo(combinedDisplay(cv::Rect(0, 0, width, height)));
            }
        }
        {
            std::unique_lock<std::mutex> lock(flipMutex);
            if (!flip.empty()) {
        	cv::resize(flip, resizedFrame2, cv::Size(width, height));
        	resizedFrame2.copyTo(combinedDisplay(cv::Rect(width, 0, width, height)));
            }
        }
        {
            std::unique_lock<std::mutex> lock(rotateMutex);
            if (!rotate.empty()) {
        	cv::resize(rotate, resizedFrame3, cv::Size(width, height));
        	resizedFrame3.copyTo(combinedDisplay(cv::Rect(0, height, width, height)));
            }
        }
        {
             std::unique_lock<std::mutex> lock(removeRedMutex);
             if (!removeRed.empty()) {
        	 cv::resize(removeRed, resizedFrame4, cv::Size(width, height));
        	 resizedFrame4.copyTo(combinedDisplay(cv::Rect(width, height, width, height)));
             }
        }
	// convert the combined matrix into Image
        if (!combinedDisplay.empty()) {
        	std::unique_lock<std::mutex> lock(imageMutex);
        	// Convert the combined display to QImage and set it to the label
		qimage = matToQImage();
        	qimage.save("out.png");
        }
    }
}

void showFramesInSections(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // Initially assign an image
    qimage = QImage(width, height, QImage::Format_RGB32);
    qimage.fill(Qt::white);
    
    // Create a large image to hold all sections
    //combinedDisplay = cv::Mat::zeros(height * 2, width * 2, CV_8UC3);  // 2x2 grid
    
    // Create a main window
    QWidget window;
    window.setWindowTitle("Real-Time Video Manipulation");
    window.resize(height * 2, width * 2);

    // Set a background color
    QPalette pal = window.palette();
    pal.setColor(QPalette::Background, QColor(45, 45, 48));  // Dark grey background
    window.setAutoFillBackground(true);
    window.setPalette(pal);

    // Create a label with some text
    QLabel *label = new QLabel(&window);
    label->setAlignment(Qt::AlignCenter);

    // Create the Play button
    QPushButton *playButton = new QPushButton("  Play");
    //#4CAF50
    playButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #FFFFFF;"  // Green color
        "  color: black;"
        "  font-size: 24px;"
        "  border-radius: 10px;"
        "  padding: 10px 20px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #45a049;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #357a38;"
        "}"
    );
    playButton->setIcon(QIcon("../icons/play_icon.png"));
    playButton->setIconSize(QSize(40, 40));

    // Create the Pause button
    QPushButton *pauseButton = new QPushButton("  Pause");
    pauseButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #FFFFFF;"  // Red color
        "  color: black;"
        "  font-size: 24px;"
        "  border-radius: 10px;"
        "  padding: 10px 20px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #e53935;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #b71c1c;"
        "}"
    );
    pauseButton->setIcon(QIcon("../icons/pause_icon.png"));
    pauseButton->setIconSize(QSize(40, 40));
    
    // Connect the buttons to lambda functions (example, no actual functionality)
    QObject::connect(playButton, &QPushButton::clicked, [=]() {
        played = true;
    });

    QObject::connect(pauseButton, &QPushButton::clicked, [=]() {
    	played = false;
    });
    
    // Set up a horizontal layout for the buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(playButton);
    buttonLayout->addWidget(pauseButton);
    
    // Set up the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(label);
    
    mainLayout->addStretch();  // Add some spacing between label and buttons
    mainLayout->addLayout(buttonLayout);

    // Set the layout on the main window
    window.setLayout(mainLayout);

    // Create a QTimer to periodically update the image
    QTimer *timer = new QTimer(&window);
    
    QObject::connect(timer, &QTimer::timeout, [&]() {
    	{
    		std::unique_lock<std::mutex> lock(imageMutex);
    		if (!combinedDisplay.empty()) {
        	    	//std::cout << "Here==========\n";
        	    	label->setPixmap(QPixmap::fromImage(qimage));
        	    	//qimage.save("out.png");
        	}
        }
    });

    // Start the timer with a 100 ms interval
    timer->start(10);
    
    // Show the window
    window.show();
    int result = app.exec();
    isRunning = false;

}

