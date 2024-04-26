#ifndef MAINDISPLAYVIEW_HPP
#define MAINDISPLAYVIEW_HPP

#include <gui_generated/maindisplay_screen/MainDisplayViewBase.hpp>
#include <gui/maindisplay_screen/MainDisplayPresenter.hpp>

#include <fdcan.h>

class MainDisplayView : public MainDisplayViewBase
{
public:
    MainDisplayView();
    virtual ~MainDisplayView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAINDISPLAYVIEW_HPP
