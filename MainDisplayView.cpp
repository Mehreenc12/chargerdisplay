#include <gui/maindisplay_screen/MainDisplayView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <stdlib.h>
//#include <fdcan.h>


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
		  vol_req = (int16_t)((RxData[0] << 8) + RxData[1]);
		  curr_req = (int16_t)((RxData[2] << 8) + RxData[3]);
		  vol_prov = (int16_t)((RxData[4] << 8) + RxData[5]);
		  curr_prov = (int16_t)((RxData[6] << 8) + RxData[7]);
		  power = (int32_t)(vol_prov * curr_prov);
		  
		}
		if(id == 0x220) {//pack status
		  hvsoc = (uint16_t)((RxData[4] << 8) + RxData[5]);
		  max_temp = (uint8_t)RxData[6];
		}
	    	hvsoc_shift = (double) hvsoc/100;
	    	power_shift = (double) abs(power)/100;
	    	timeleft = 6.8 * (1-hvsoc_shift) / power_shift; //time is in hours
	    	timeInMins = (int) (timeleft*60.0);


	    

	    //voltage required
	        if(vol_req < 0){
			vrdig_sign.setTypedText(touchgfx::TypedText(T_TEXT_MINUS));
		}else{
			vrdig_sign.setTypedText(touchgfx::TypedText(T_TEXT_PLUS));
		}
	    	vrdig_sign.invalidate();
	    
	    
	    switch((abs(vol_req))%10) {
	    case 0:
	        vrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        vrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        vrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        vrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        vrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        vrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        vrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        vrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        vrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        vrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        vrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		vrdig_3.invalidate();


	    switch((abs(vol_req)) / 10 % 10) {
	    case 0:
	        vrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        vrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        vrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        vrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        vrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        vrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        vrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        vrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        vrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        vrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        vrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		vrdig_2.invalidate();


	    switch((abs(vol_req)) / 100 % 10) {
	    case 0:
	        vrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        vrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        vrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        vrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        vrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        vrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        vrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        vrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        vrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        vrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        vrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		vrdig_1.invalidate();


	    switch((abs(vol_req)) / 1000) {
	    case 0:
	        vrdig.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        vrdig.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        vrdig.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        vrdig.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        vrdig.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        vrdig.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        vrdig.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        vrdig.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        vrdig.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        vrdig.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        vrdig.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		vrdig.invalidate();





	    	    //voltage provided
	        if(vol_prov < 0){
			vpdig_sign.setTypedText(touchgfx::TypedText(T_TEXT_MINUS));
		}else{
			vpdig_sign.setTypedText(touchgfx::TypedText(T_TEXT_PLUS));
		}
	    	vpdig_sign.invalidate();
	    
	    
	    switch((abs(vol_prov))%10) {
	    case 0:
	        vpdig_3.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        vpdig_3.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        vpdig_3.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        vpdig_3.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        vpdig_3.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        vpdig_3.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        vpdig_3.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        vpdig_3.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        vpdig_3.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        vpdig_3.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        vpdig_3.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		vpdig_3.invalidate();


	    switch((abs(vol_prov)) / 10 % 10) {
	    case 0:
	        vpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        vpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        vpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        vpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        vpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        vpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        vpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        vpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        vpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        vpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        vpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		vpdig_2.invalidate();


	    switch((abs(vol_prov)) / 100 % 10) {
	    case 0:
	        vpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        vpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        vpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        vpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        vpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        vpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        vpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        vpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        vpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        vpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        vpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		vpdig_1.invalidate();


	    switch((abs(vol_prov)) / 1000) {
	    case 0:
	        vpdig.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        vpdig.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        vpdig.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        vpdig.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        vpdig.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        vpdig.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        vpdig.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        vpdig.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        vpdig.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        vpdig.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        vpdig.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		vpdig.invalidate();



	    	    //curr required
	        if(curr_req < 0){
			crdig_sign.setTypedText(touchgfx::TypedText(T_TEXT_MINUS));
		}else{
			crdig_sign.setTypedText(touchgfx::TypedText(T_TEXT_PLUS));
		}
	    	crdig_sign.invalidate();


	    switch((abs(curr_req)) % 10) {
	    case 0:
	        crdig_2.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        crdig_2.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        crdig_2.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        crdig_2.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        crdig_2.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        crdig_2.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        crdig_2.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        crdig_2.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        crdig_2.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        crdig_2.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        crdig_2.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		crdig_2.invalidate();


	    switch((abs(curr_req)) / 10 % 10) {
	    case 0:
	        crdig_1.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        crdig_1.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        crdig_1.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        crdig_1.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        crdig_1.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        crdig_1.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        crdig_1.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        crdig_1.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        crdig_1.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        crdig_1.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        crdig_1.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		crdig_1.invalidate();


	    switch((abs(curr_req)) / 100) {
	    case 0:
	        crdig.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        crdig.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        crdig.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        crdig.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        crdig.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        crdig.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        crdig.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        crdig.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        crdig.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        crdig.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        crdig.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		crdig.invalidate();




	    	 //curr provided
	        if(curr_prov < 0){
			cpdig_sign.setTypedText(touchgfx::TypedText(T_TEXT_MINUS));
		}else{
			cpdig_sign.setTypedText(touchgfx::TypedText(T_TEXT_PLUS));
		}
	    	cpdig_sign.invalidate();


	    switch((abs(curr_prov)) % 10) {
	    case 0:
	        cpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        cpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        cpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        cpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        cpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        cpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        cpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        cpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        cpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        cpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        cpdig_2.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		cpdig_2.invalidate();


	    switch((abs(curr_prov)) / 10 % 10) {
	    case 0:
	        cpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        cpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        cpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        cpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        cpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        cpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        cpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        cpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        cpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        cpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        cpdig_1.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		cpdig_1.invalidate();


	    switch((abs(curr_prov)) / 100) {
	    case 0:
	        cpdig.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        cpdig.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        cpdig.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        cpdig.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        cpdig.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        cpdig.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        cpdig.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        cpdig.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        cpdig.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        cpdig.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        cpdig.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		cpdig.invalidate();




	      //power
	        if(power < 0){
			pwrdig_sign.setTypedText(touchgfx::TypedText(T_TEXT_MINUS));
		}else{
			pwrdig_sign.setTypedText(touchgfx::TypedText(T_TEXT_PLUS));
		}
	    	pwrdig_sign.invalidate();


	    switch((abs(power)) % 10) {
	    case 0:
	        pwrdig_6.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        pwrdig_6.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        pwrdig_6.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        pwrdig_6.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        pwrdig_6.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        pwrdig_6.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        pwrdig_6.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        pwrdig_6.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        pwrdig_6.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        pwrdig_6.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        pwrdig_6.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		pwrdig_6.invalidate();


	    switch((abs(power)) / 10 % 10) {
	    case 0:
	        pwrdig_5.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        pwrdig_5.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        pwrdig_5.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        pwrdig_5.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        pwrdig_5.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        pwrdig_5.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        pwrdig_5.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        pwrdig_5.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        pwrdig_5.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        pwrdig_5.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        pwrdig_5.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		pwrdig_5.invalidate();



	    	switch((abs(power)) / 100 % 10) {
	    case 0:
	        pwrdig_4.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        pwrdig_4.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        pwrdig_4.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        pwrdig_4.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        pwrdig_4.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        pwrdig_4.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        pwrdig_4.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        pwrdig_4.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        pwrdig_4.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        pwrdig_4.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        pwrdig_4.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		pwrdig_4.invalidate();



	    	switch((abs(power)) / 1000 % 10) {
	    case 0:
	        pwrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        pwrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        pwrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        pwrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        pwrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        pwrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        pwrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        pwrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        pwrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        pwrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        pwrdig_3.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		pwrdig_3.invalidate();



	    	switch((abs(power)) / 10000 % 10) {
	    case 0:
	        pwrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        pwrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        pwrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        pwrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        pwrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        pwrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        pwrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        pwrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        pwrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        pwrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        pwrdig_2.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		pwrdig_2.invalidate();



	    	switch((abs(power)) / 100000 % 10) {
	    case 0:
	        pwrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        pwrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        pwrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        pwrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        pwrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        pwrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        pwrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        pwrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        pwrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        pwrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        pwrdig_1.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		pwrdig_1.invalidate();




	    	switch((abs(power)) / 1000000) {
	    case 0:
	        pwrdig.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        pwrdig.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        pwrdig.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        pwrdig.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        pwrdig.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        pwrdig.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        pwrdig.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        pwrdig.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        pwrdig.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        pwrdig.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        pwrdig.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		pwrdig.invalidate();



	    	//state of charge

	    	switch(hvsoc % 10) {
	    case 0:
	        socdig_4.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        socdig_4.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        socdig_4.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        socdig_4.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        socdig_4.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        socdig_4.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        socdig_4.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        socdig_4.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        socdig_4.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        socdig_4.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        socdig_4.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		socdig_4.invalidate();



	    	switch(hvsoc / 10 % 10) {
	    case 0:
	        socdig_3.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        socdig_3.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        socdig_3.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        socdig_3.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        socdig_3.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        socdig_3.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        socdig_3.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        socdig_3.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        socdig_3.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        socdig_3.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        socdig_3.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		socdig_3.invalidate();



	    	switch(hvsoc / 100 % 10) {
	    case 0:
	        socdig_2.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        socdig_2.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        socdig_2.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        socdig_2.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        socdig_2.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        socdig_2.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        socdig_2.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        socdig_2.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        socdig_2.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        socdig_2.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        socdig_2.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		socdig_2.invalidate();



	    	switch(hvsoc / 1000 % 10) {
	    case 0:
	        socdig_1.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        socdig_1.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        socdig_1.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        socdig_1.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        socdig_1.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        socdig_1.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        socdig_1.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        socdig_1.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        socdig_1.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        socdig_1.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        socdig_1.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		socdig_1.invalidate();




	    	switch(hvsoc / 10000) {
	    case 0:
	        socdig.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        socdig.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        socdig.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        socdig.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        socdig.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        socdig.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        socdig.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        socdig.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        socdig.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        socdig.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        socdig.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		socdig.invalidate();



	    //max temp

	    	switch(max_temp % 10) {
	    case 0:
	        tempdig_2.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        tempdig_2.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        tempdig_2.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        tempdig_2.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        tempdig_2.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        tempdig_2.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        tempdig_2.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        tempdig_2.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        tempdig_2.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	       tempdig_2.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        tempdig_2.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		tempdig_2.invalidate();



	    	switch(max_temp / 10 % 10) {
	    case 0:
	        tempdig_1.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        tempdig_1.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        tempdig_1.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        tempdig_1.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        tempdig_1.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        tempdig_1.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        tempdig_1.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        tempdig_1.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        tempdig_1.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        tempdig_1.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        tempdig_1.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		tempdig_1.invalidate();



	    	switch(max_temp /100) {
	    case 0:
	        tempdig.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        tempdig.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        tempdig.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        tempdig.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        tempdig.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        tempdig.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        tempdig.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        tempdig.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        tempdig.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	        tempdig.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        tempdig.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		tempdig.invalidate();






	    	    //time remaining

	    	switch((timeInMins%60) % 10) {
	    case 0:
	        timedig_3.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        timedig_3.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        timedig_3.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        timedig_3.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        timedig_3.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        timedig_3.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        timedig_3.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        timedig_3.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        timedig_3.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	       timedig_3.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        timedig_3.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		timedig_3.invalidate();



	    	switch((timeInMins%60) / 10) {
	    case 0:
	        timedig_2.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        timedig_2.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        timedig_2.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        timedig_2.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        timedig_2.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        timedig_2.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        timedig_2.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        timedig_2.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        timedig_2.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	       timedig_2.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        timedig_2.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		timedig_2.invalidate();


	    
	    	switch((timeInMins/60) % 10) {
	    case 0:
	        timedig_1.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        timedig_1.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        timedig_1.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        timedig_1.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        timedig_1.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        timedig_1.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        timedig_1.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        timedig_1.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        timedig_1.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	       timedig_1.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        timedig_1.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		timedig_1.invalidate();




	    	switch((timeInMins/60) / 10) {
	    case 0:
	        timedig.setTypedText(touchgfx::TypedText(T_TEXT_0));
	        break;
	    case 1:
	        timedig.setTypedText(touchgfx::TypedText(T_TEXT_1));
	        break;
	    case 2:
	        timedig.setTypedText(touchgfx::TypedText(T_TEXT_2));
	        break;
	    case 3:
	        timedig.setTypedText(touchgfx::TypedText(T_TEXT_3));
	        break;
	    case 4:
	        timedig.setTypedText(touchgfx::TypedText(T_TEXT_4));
	        break;
	    case 5:
	        timedig.setTypedText(touchgfx::TypedText(T_TEXT_5));
	        break;
	    case 6:
	        timedig.setTypedText(touchgfx::TypedText(T_TEXT_6));
	        break;
	    case 7:
	        timedig.setTypedText(touchgfx::TypedText(T_TEXT_7));
	        break;
	    case 8:
	        timedig.setTypedText(touchgfx::TypedText(T_TEXT_8));
	        break;
	    case 9:
	       timedig.setTypedText(touchgfx::TypedText(T_TEXT_9));
	        break;
             default:
	        timedig.setTypedText(touchgfx::TypedText(T_TEXT_ERROR));
		break;
	     }
		timedig.invalidate();

	    
	    


	    
    }    
    
}
    
