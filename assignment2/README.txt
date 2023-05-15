Name: Kaitlyn Warhurst
Student Number: 101217643

Compilation Instructions:
    In the terminal in the file directory containing all the files, use the following commandline: make all
    which will make all the files into a single excutable

Exection Instructions:
    In the terminal in the file directory containing all the files, use the following commandline: ./main
    which will execute the file

Files: 
    Date (Entity Object):
    Date.h - contains the class Date and all Date's function/method declarations and all the information about the Date
    Date.cc - contains the definitions of all the Date's functions and methods 

    Photo (Entity Object):
    Photo.h - contains the class Photo and all Photo's function/method declarations and all the information about the photo
    Photo.cc - contains the definitions of all the Photo's functions and methods 

    PhotoArray (Collection Object):
    PhotoArray.h - contains the class PhotoArray and all PhotoArray's function/method declarations and is a Data structure of photos
    PhotoArray.cc - contains the definitions of all the PhotoArray's functions and methods

    Album (Entity Object):
    Album.h - contains the class Album and all the Album's function/method declarations and all the information pertaining to Album
    Album.cc - contains the definitions of all the Album's functions and methods

    AlbumArray (Collection object):
    AlbumArray.h - contains the class AlbumArray and all the AlbumArray's function/method declarations and all the information pertaining to AlbumArray
    AlbumArray.cc - contains the definitions of all the AlbumArray's functions and methods

    PhotoGram (Control Object):
    PhotoGram.h - contains the class PhotoGram and all the PhotoGram's function/method declarations and manages a collection of Albums and provides services to Client
    PhotoGram.cc - contains the definitions of all the PhotoGram's functions and methods

    Client (Control Object) - 'connects' to the PhotoGram network to display Photos or download Albums:
    Client.h - contains the class Client and all the Client's function/method declarations and manages a collection of downloaded Albums 
    Client.cc - contains the definitions of all the Client's functions and methods

    TestControl (Control Object)- controls the running of tests on the application and interacts with TestView
    TestControl.h -contains the class TestControl and all the TestControl's function/method declarations
    TestControl.cc - contains the defintions of all the TestControl functions and methods

    TestView (BoundaryObject) - Takes input from the user to run tests
    TestView.h - contains the class TestView and all the TestView's functions/method declarations
    TestView.h - contains the definitons of all the TestView functions and methods

    main.cc contains the main function and launches the TestView

    






