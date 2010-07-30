/*
============================================================================
 Name        : FlashLite21LauncherDocument.h
 Author      : Abdul Qabiz
 Copyright   : © 2007-2008 Abdul Qabiz (http://www.abdulqabiz.com)
 Description : Declares document class for application.
============================================================================
*/

#ifndef FLASHLITE21LAUNCHERDOCUMENT_H
#define FLASHLITE21LAUNCHERDOCUMENT_H

// INCLUDES
#include <akndoc.h>

// CONSTANTS

// FORWARD DECLARATIONS
class  CEikAppUi;

// CLASS DECLARATION

/**
*  CFlashLite21LauncherDocument application class.
*/
class CFlashLite21LauncherDocument : public CAknDocument
    {
    public: // Constructors and destructor
        /**
        * Two-phased constructor.
        */
        static CFlashLite21LauncherDocument* NewL(CEikApplication& aApp);

        /**
        * Destructor.
        */
        virtual ~CFlashLite21LauncherDocument();

    public: // New functions

    public: // Functions from base classes
    protected:  // New functions

    protected:  // Functions from base classes

    private:

        /**
        * EPOC default constructor.
        */
        CFlashLite21LauncherDocument(CEikApplication& aApp);
        void ConstructL();

    private:

        /**
        * From CEikDocument, create CFlashLite21LauncherAppUi "App UI" object.
        */
        CEikAppUi* CreateAppUiL();
    };

#endif



