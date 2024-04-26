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
        
    }    
    
}
    
