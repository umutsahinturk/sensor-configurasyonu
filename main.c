#include <stdio.h>

int main()
{
    enum AccelRange
    {
        _2G,
        _4G,
        _8G,
        _16G
    };

    enum Bandwidth
    {
        _7_81Hz,
        _15_63Hz,
        _31_25Hz,
        _62_5Hz,
        _125Hz,
        _250Hz,
        _500Hz,
        _1000Hz,
    };

    enum OperationMode 
    {
        Normal,
        Suspend,
        LowPower1,
        Standby,
        LowPower2,
        DeepSuspend
    };


    return 0;
}