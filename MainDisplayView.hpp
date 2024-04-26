#ifndef MAINDISPLAYVIEW_HPP
#define MAINDISPLAYVIEW_HPP

#include <gui_generated/maindisplay_screen/MainDisplayViewBase.hpp>
#include <gui/maindisplay_screen/MainDisplayPresenter.hpp>
#include <texts/TextKeysAndLanguages.hpp>

#include <fdcan.h>

class MainDisplayView : public MainDisplayViewBase
{
public:

    volatile uint32_t id;
    FDCAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[8];

    int16_t vol_req;
    int16_t curr_req;
    int16_t vol_prov;
    int16_t curr_prov;
    uint16_t hvsoc;
    uint8_t max_temp;
    uint16_t timeleft;
    int32_t power;

    MainDisplayView();
    virtual ~MainDisplayView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void updateCharge();
protected:
};

#endif // MAINDISPLAYVIEW_HPP
