# Flutter

    flutter is a framework for developing android applications. It is developed by google. It uses dart programming language for development

## Layers of flutter

    1.	Dart layer: This is the programming language that is used to write the code for the app. Dart is an object-oriented programming language that is optimized for client-side development.

    2.	Framework layer: This layer consists of the widgets and tools provided by the Flutter framework. The framework provides a rich set of widgets, such as buttons, text, images, and input fields, which can be combined to create the user interface of the app.

    3.	Engine layer: This layer is responsible for the rendering and animation of the app. The engine is written in C++ and is responsible for managing the layout, painting, and compositing of the widgets.

    4.	Platform layer: This layer provides access to platform-specific features and APIs. Flutter has plugins and packages that allow developers to access native functionality, such as camera, location, and sensors.

    5.	Application layer: This layer consists of the code that is written specifically for the app. It includes the business logic, network communication, and data storage.

## Components of flutter

    •	Widgets – everything in flutter is a widget. A widget is a reusable code component that can be used by other widgets to create a user interface

    •	Stateful widgets – These widgets can change their appearance or behaviour time based on the change in state

    •	Hot reload – this feature allows to make changes in the the code and see the changes in the app most instantly, without restarting the app

    •	Rendering engine: Flutter has its own rendering engine, which is used to create the user interface. This engine allows for fast rendering and smooth animations.

    •	Platform-specific widgets: Flutter provides widgets that look and feel like native widgets on different platforms, such as iOS and Android.

## Steps down the line of creating first flutter app
    1.	 Edited pubspec.yaml file

    2.	 Edited analysis_option.yaml file ( to tell the dart analyser to take it easy)

    3.	In the code lab app, we are learning to how to manage states and stuff related to updation and rendering of states based in the change in states etc. (https://codelabs.developers.google.com/codelabs/flutter-codelab-first#3) . This explains everything.

## General Notes
    
    - Everything in flutter is a widget, Widgets are the elements from which you build every Flutter app. 

    - Concept of extracting the widget – (https://codelabs.developers.google.com/codelabs/flutter-codelab-first#4) (Extract the widget part)

    - Stateless VS Stateful widget – (https://youtu.be/8sAyPDLorek?t=4282) (https://codelabs.developers.google.com/codelabs/flutter-codelab-first#6). We don’t want to put all our states in MyAppState class as other stateless widgets don’t to access all the states in MyAppState and don’t want to get notified when ant state changes, So the concept of stateful widget arises. Stateful widgets have their own state and can rebuild themselves as the state changes.

    -   In Flutter, defining variables inside and outside the build method can affect the scope and lifetime of the variables.
        Variables defined outside the build method have a global scope, meaning they can be accessed from anywhere within the class. These variables can also persist between builds, so their values are retained even after the build method is called again. However, this can also cause issues with memory management and performance, especially if the variable is holding a large amount of data.
        On the other hand, variables defined inside the build method have a local scope, meaning they can only be accessed within the build method itself. These variables are recreated every time the build method is called, so their values are reset to their initial values with each rebuild. This can be useful for temporary variables or variables that hold data that is only needed during the build process.
        In general, it is recommended to define variables outside the build method if they are needed across multiple builds or if they hold data that should persist across builds. Variables should be defined inside the build method if they are only needed during the build process and have a small memory footprint.
