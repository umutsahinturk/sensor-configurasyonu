#include <stdio.h>
#include <stdint.h>

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

    return 0;
}