#include <stdio.h>
#include <stdint.h>

#define ACCEL_RANGE AFS_8G
#define BAND_WIDTH Band_500Hz
#define OPERATION_MODE Mode_Normal

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
    
    struct AccConfig Config = {ACCEL_RANGE, BAND_WIDTH, OPERATION_MODE, 0b00000000};

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
    printf("AccConfigValue(Decimal): %d\n", sayi);
}

void HexadecimalDegerYazdir(int sayi)
{
        printf("AccConfigValue(Hexadecimal): 0x%02x\n", sayi);
}

void BinaryDegerYazdir(int sayi)
{
    printf("AccConfigValue(Binary): 0b");

    int sonuc[8] = {0};

    for(int i = 7; i >= 0; i--)
    {
        sonuc[i] = sayi % 2;
        sayi /= 2; 
    }
    
    for(int i = 0; i < 8; i++)
    {
        printf("%d", sonuc[i]);
    }
    printf("\n");
}
