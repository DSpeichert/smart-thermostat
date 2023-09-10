// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.6
// Project name: Thermostat

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////

// SCREEN: ui_MainScreen
void ui_MainScreen_screen_init(void);
void ui_event_MainScreen(lv_event_t * e);
lv_obj_t * ui_MainScreen;
void ui_event_TimeLabel(lv_event_t * e);
lv_obj_t * ui_TimeLabel;
void ui_event_StatusLabel(lv_event_t * e);
lv_obj_t * ui_StatusLabel;
void ui_event_TempLabel(lv_event_t * e);
lv_obj_t * ui_TempLabel;
void ui_event_HumidityLabel(lv_event_t * e);
lv_obj_t * ui_HumidityLabel;
void ui_event_ModeDropdown(lv_event_t * e);
lv_obj_t * ui_ModeDropdown;
void ui_event_SetupBtn(lv_event_t * e);
lv_obj_t * ui_SetupBtn;
lv_obj_t * ui_SetupLabel;
lv_obj_t * ui_SetTempBg1;
lv_obj_t * ui_SetTempBg;
void ui_event_TempArc(lv_event_t * e);
lv_obj_t * ui_TempArc;
lv_obj_t * ui_SetTemp;
lv_obj_t * ui_SetTempFrac;
void ui_event_TempDecreaseBtn(lv_event_t * e);
lv_obj_t * ui_TempDecreaseBtn;
lv_obj_t * ui_TempDecreaseLabel;
void ui_event_TempIncreaseBtn(lv_event_t * e);
lv_obj_t * ui_TempIncreaseBtn;
lv_obj_t * ui_TempIncreaseLabel;
void ui_event_InfoBtn(lv_event_t * e);
lv_obj_t * ui_InfoBtn;
lv_obj_t * ui_InfoLabel;
lv_obj_t * ui_WifiIndicatorLabel;

// SCREEN: ui_Info
void ui_Info_screen_init(void);
void ui_event_Info(lv_event_t * e);
lv_obj_t * ui_Info;
lv_obj_t * ui_WifiConnectedLabel;
lv_obj_t * ui_WifiConnCheckBox;
lv_obj_t * ui_WifiSsidLabel;
lv_obj_t * ui_IPLabel;
lv_obj_t * ui_HostnameLabel;
lv_obj_t * ui_RssiLabel;
lv_obj_t * ui_FwVersionLabel;
lv_obj_t * ui_BuildDateLabel;
lv_obj_t * ui_CopyrightLabel;
void ui_event_ShowQR(lv_event_t * e);
lv_obj_t * ui_ShowQR;
lv_obj_t * ui_ShowQRLabel;
void ui_event_HomeBtn(lv_event_t * e);
lv_obj_t * ui_HomeBtn;
lv_obj_t * ui_HomeLabel;

// SCREEN: ui_Setup
void ui_Setup_screen_init(void);
void ui_event_Setup(lv_event_t * e);
lv_obj_t * ui_Setup;
lv_obj_t * ui_TempUnitsLabel;
lv_obj_t * ui_FahrenheitLabel;
lv_obj_t * ui_TempUnitsSwitch;
lv_obj_t * ui_CelciusLabel;
lv_obj_t * ui_TempCorrectionTextLabel;
lv_obj_t * ui_TempCorrectionLabel;
void ui_event_TempCorrectionSlider(lv_event_t * e);
lv_obj_t * ui_TempCorrectionSlider;
lv_obj_t * ui_TempSwingTextLabel;
lv_obj_t * ui_TempSwingLabel;
void ui_event_TempSwingSlider(lv_event_t * e);
lv_obj_t * ui_TempSwingSlider;
lv_obj_t * ui_HvacCoolLabel;
lv_obj_t * ui_HvacCoolCheckbox;
lv_obj_t * ui_HvacFanLabel;
lv_obj_t * ui_HvacFanCheckbox;
void ui_event_SetupUncommonBtn(lv_event_t * e);
lv_obj_t * ui_SetupUncommonBtn;
lv_obj_t * ui_SetupUncommonLabel;
void ui_event_SetupHomeBtn(lv_event_t * e);
lv_obj_t * ui_SetupHomeBtn;
lv_obj_t * ui_SetupHomeLabel;
lv_obj_t * ui_MatterLabel;
lv_obj_t * ui_MatterCheckbox;

// SCREEN: ui_LessCommonSetup
void ui_LessCommonSetup_screen_init(void);
void ui_event_LessCommonSetup(lv_event_t * e);
lv_obj_t * ui_LessCommonSetup;
void ui_event_CalibrateBtn(lv_event_t * e);
lv_obj_t * ui_CalibrateBtn;
lv_obj_t * ui_CalibrateLabel;
lv_obj_t * ui_TimezoneLabel1;
lv_obj_t * ui_TimezoneDropdown;
lv_obj_t * ui_UiSleepTextLabel;
lv_obj_t * ui_UiSleepLabel;
void ui_event_UiSleepSlider(lv_event_t * e);
lv_obj_t * ui_UiSleepSlider;
lv_obj_t * ui_DualStageHeatLabel;
lv_obj_t * ui_Hvac2StageHeatCheckbox;
lv_obj_t * ui_DisableLabel1;
lv_obj_t * ui_RevValveCheckbox;
lv_obj_t * ui_DisableBeepLabel;
lv_obj_t * ui_AudibleBeepCheckbox;
void ui_event_SetupWifiBtn(lv_event_t * e);
lv_obj_t * ui_SetupWifiBtn;
lv_obj_t * ui_SetupWifiLabel;
void ui_event_SetupHomeBtn2(lv_event_t * e);
lv_obj_t * ui_SetupHomeBtn2;
lv_obj_t * ui_SetupHomeLabel2;

// SCREEN: ui_WifiConfig
void ui_WifiConfig_screen_init(void);
lv_obj_t * ui_WifiConfig;
lv_obj_t * ui_Keyboard;
lv_obj_t * ui_PSK;
lv_obj_t * ui_PwdLabel;
void ui_event_SsidDropdown(lv_event_t * e);
lv_obj_t * ui_SsidDropdown;
void ui_event_ScanBtn(lv_event_t * e);
lv_obj_t * ui_ScanBtn;
lv_obj_t * ui_ScanLabel;
void ui_event_SaveBtn(lv_event_t * e);
lv_obj_t * ui_SaveBtn;
lv_obj_t * ui_SaveLabel;
void ui_event_CancelBtn(lv_event_t * e);
lv_obj_t * ui_CancelBtn;
lv_obj_t * ui_CancelLabel;
void ui_event_WifiStatusLabel(lv_event_t * e);
lv_obj_t * ui_WifiStatusLabel;

// SCREEN: ui_MatterConfig
void ui_MatterConfig_screen_init(void);
void ui_event_MatterConfig(lv_event_t * e);
lv_obj_t * ui_MatterConfig;
void ui_event_QrHomeBtn(lv_event_t * e);
lv_obj_t * ui_QrHomeBtn;
lv_obj_t * ui_SetupHomeLabel1;
lv_obj_t * ui_QRImage;
lv_obj_t * ui_ManualPairingCode;

// SCREEN: ui_ThermostatRestart
void ui_ThermostatRestart_screen_init(void);
void ui_event_ThermostatRestart(lv_event_t * e);
lv_obj_t * ui_ThermostatRestart;
lv_obj_t * ui_Notification;
lv_obj_t * ui_RestartCountdown;
lv_obj_t * ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    // #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_MainScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
    }
}
void ui_event_TimeLabel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
    }
}
void ui_event_StatusLabel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
    }
}
void ui_event_TempLabel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
    }
}
void ui_event_HumidityLabel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
    }
}
void ui_event_ModeDropdown(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        tftHvacModeChange(e);
        tftBeep(e);
    }
    if(event_code == LV_EVENT_CLICKED) {
        tftStopTouchTimer(e);
    }
}
void ui_event_SetupBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Setup, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Setup_screen_init);
        tftStopTouchTimer(e);
        tftBeep(e);
    }
}
void ui_event_TempArc(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        tftUpdateTempSet(e);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        tftUpdateTempSet(e);
    }
    if(event_code == LV_EVENT_RELEASED) {
        tftBeep(e);
    }
}
void ui_event_TempDecreaseBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
        tftDecreaseSetTemp(e);
    }
}
void ui_event_TempIncreaseBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
        tftIncreaseSetTemp(e);
    }
}
void ui_event_InfoBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Info, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Info_screen_init);
        tftStopTouchTimer(e);
        tftBeep(e);
    }
}
void ui_event_Info(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        LoadInfoStrings(e);
    }
}
void ui_event_ShowQR(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftBeep(e);
        _ui_screen_change(&ui_MatterConfig, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_MatterConfig_screen_init);
    }
}
void ui_event_HomeBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
        _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_MainScreen_screen_init);
    }
}
void ui_event_Setup(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        LoadConfigSettings(e);
    }
}
void ui_event_TempCorrectionSlider(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        tftUpdateTempCorrectionValue(e);
    }
}
void ui_event_TempSwingSlider(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        tftUpdateTempSwingValue(e);
    }
}
void ui_event_SetupUncommonBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_LessCommonSetup, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_LessCommonSetup_screen_init);
        tftBeep(e);
        LoadUncommonSettings(e);
    }
}
void ui_event_SetupHomeBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
        _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_MainScreen_screen_init);
        SaveConfigSettings(e);
    }
}
void ui_event_LessCommonSetup(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        LoadConfigSettings(e);
    }
}
void ui_event_CalibrateBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftCalibrate(e);
    }
}
void ui_event_UiSleepSlider(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        tftUpdateUiSleepValue(e);
    }
}
void ui_event_SetupWifiBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_WifiConfig, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_WifiConfig_screen_init);
        tftClearPsk(e);
        tftBeep(e);
    }
}
void ui_event_SetupHomeBtn2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
        _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_MainScreen_screen_init);
        SaveUncommonConfigSettings(e);
    }
}
void ui_event_SsidDropdown(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        tftBeep(e);
    }
}
void ui_event_ScanBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        StartWifiScan(e);
    }
}
void ui_event_SaveBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftSetNewWifi(e);
        _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 2, &ui_MainScreen_screen_init);
        tftAwaken(e);
    }
}
void ui_event_CancelBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Setup, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_Setup_screen_init);
        tftBeep(e);
        stopWifiScan(e);
    }
}
void ui_event_WifiStatusLabel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
    }
}
void ui_event_MatterConfig(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
#ifdef MATTER_ENABLED
        ShowQrOnScreen(e);
#endif
    }
}
void ui_event_QrHomeBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        tftAwaken(e);
        _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_MainScreen_screen_init);
    }
}
void ui_event_ThermostatRestart(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        tftCountdown(e);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_MainScreen_screen_init();
    ui_Info_screen_init();
    ui_Setup_screen_init();
    ui_LessCommonSetup_screen_init();
    ui_WifiConfig_screen_init();
    ui_MatterConfig_screen_init();
    ui_ThermostatRestart_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_MainScreen);
}
