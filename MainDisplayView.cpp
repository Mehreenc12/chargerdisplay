#include <gui/maindisplay_screen/MainDisplayView.hpp>
#include <texts/TextKeysAndLanguages.hpp>


MainDisplayView::MainDisplayView()
{

}

void MainDisplayView::setupScreen()
{
    MainDisplayViewBase::setupScreen();
}

void MainDisplayView::tearDownScreen()
{
    MainDisplayViewBase::tearDownScreen();
}

void MainDisplayView::updateCharge(){

    while(HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &RxHeader, RxData)==HAL_OK){
        id = RxHeader.Identifier;
		if(id == 0x223) {//ccs info
		  vol_req = (int16_t)RxData[0];
		  curr_req = (int16_t)RxData[2];
		  vol_prov = (int16_t)RxData[4];
		  curr_prov = (int16_t)RxData[6];
		}
		if(id == 0x220) {//pack status
		  time_seconds = (uint8_t)RxData[0];
		  time_minutes = (uint8_t)RxData[1];
		}
    }    
    
}
    
