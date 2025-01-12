#include <stdio.h>
#include <stdint.h>

#define ACCEL_RANGE AFS_8G // G Range parapetresi
#define BAND_WIDTH Band_500Hz // Bandwidth parametresi
#define OPERATION_MODE Mode_Normal // Operation Mode parametresi

void DecimalDegerYazdir(int sayi); // AccConfigValue'yi decimal olarak ekrana bastıran fonksiyon
void HexadecimalDegerYazdir(int sayi); // AccConfigValue'yi hexadecimal olarak ekrana bastıran fonksiyon
void BinaryDegerYazdir(int sayi); // AccConfigValue'yi binary olarak ekrana bastıran fonksiyon

int main()
{
    enum AccelRange // G Range değerlerini içeren enum yapısı
    {
        AFS_2G,
        AFS_4G,
        AFS_8G,
        AFS_16G
    };

    enum BandWidth // Bandwidth değerlerini içeren enum yapısı
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

    enum OperationMode // Operation Mode değerlerini içeren enum yapısı
    {
        Mode_Normal,
        Mode_Suspend,
        Mode_LowPower1,
        Mode_Standby,
        Mode_LowPower2,
        Mode_DeepSuspend
    };

    struct AccConfig // Accelerometer Configuration değerlerini içeren struct yapısı
    {
        enum AccelRange AccelRange;
        enum BandWidth BandWidth;
        enum OperationMode OperationMode;
        uint8_t AccConfigValue;
    };
    
    struct AccConfig Config = {ACCEL_RANGE, BAND_WIDTH, OPERATION_MODE, 0b00000000};

    // AccConfigValue değerini bitwise operatörleri kullanarak hesaplıyoruz.
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
        printf("AccConfigValue(Hexadecimal): 0x%02x\n", sayi); // Bu kodu GitHub readme'sinde açıkladım.
}

void BinaryDegerYazdir(int sayi)
{
    printf("AccConfigValue(Binary): 0b");

    int sonuc[8] = {0}; // 8 basamaklı sonuç arrayi

    for(int i = 7; i >= 0; i--) // Bu kodda yapılan işlemleri detaylı bir şekilde ödev dosyasında açıkladım.
    {
        sonuc[i] = sayi % 2; // İşemden kalan sonuç arrayine yazılır.
        sayi /= 2; 
    }
    
    for(int i = 0; i < 8; i++)
    {
        printf("%d", sonuc[i]); // Sonuç arrayini bastır.
    }
    printf("\n");
}
