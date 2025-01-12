#include <stdio.h>
#include <stdint.h>

void DecimalDegerYazdir(int sayi);

void HexadecimalDegerYazdir(int sayi);

void BinaryDegerYazdir(int sayi);

int main()
{
    enum AccelRange
    {
        AFS_2G,
        AFS_4G,
        AFS_8G,
        AFS_16G
    };

    enum BandWidth
    {
        Band_7_81Hz,
        Band_15_63Hz,
        Band_31_25Hz,
        Band_62_5Hz,
        Band_125Hz,
        Band_250Hz,
        Band_500Hz,
        Band_1000Hz,
    };

    enum OperationMode 
    {
        Mode_Normal,
        Mode_Suspend,
        Mode_LowPower1,
        Mode_Standby,
        Mode_LowPower2,
        Mode_DeepSuspend
    };

    struct AccConfig
    {
        enum AccelRange AccelRange;
        enum BandWidth BandWidth;
        enum OperationMode OperationMode;
        uint8_t AccConfigValue;
    };
    
    struct AccConfig Config = {AFS_8G, Band_500Hz, Mode_Normal, 0b00000000};

    Config.AccConfigValue = Config.AccConfigValue | Config.OperationMode; // 0b00000000
    Config.AccConfigValue = Config.AccConfigValue << 3; // 0b00000000
    
    Config.AccConfigValue = Config.AccConfigValue | Config.BandWidth; // 0b00000110
    Config.AccConfigValue = Config.AccConfigValue << 2; // 0b00011000
    
    Config.AccConfigValue = Config.AccConfigValue | Config.AccelRange; // 0b00011010


    DecimalDegerYazdir(Config.AccConfigValue);
    HexadecimalDegerYazdir(Config.AccConfigValue);
    BinaryDegerYazdir(Config.AccConfigValue);
    
    return 0;
}

void DecimalDegerYazdir(int sayi)
{

}

void HexadecimalDegerYazdir(int sayi)
{

}

void BinaryDegerYazdir(int sayi)
{

}