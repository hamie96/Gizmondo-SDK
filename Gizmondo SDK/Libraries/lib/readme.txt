Readme for libSDProt
--------------------

BOOL SDP_Init(const char* ProdIdString)
  This function must be called as the FIRST function in the application.
  If the function returns FALSE the app should exit immediately without
  prompting the user.
  The product id passed must be a valid 10 character gizmondo product id
  (e.g. GZGA123456).


void SDP_Deinit(void)
  This should be called immediately before the app exits to clean up any
  resources used by the library.


BOOL SDP_IsSDInserted(void)
BOOL SDP_IsSDValid(void)
  These status functions should be called once per frame during the game loop.
  The application must respond to missing or invalid SD cards as specifid in
  GCR.


void SDP_ReturnFromPowerMenu(void)
  If the user presses the power button and the game switches to the power menu,
  this function must be called upon the app being reactivated after the power
  menu has closed. This is because the user may suspend the gizmondo and change
  or remove the SD card before resuming the game.
