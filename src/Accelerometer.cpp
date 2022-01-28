#include "Accelerometer.hpp"

namespace WappieJump
{
    Accelerometer::Accelerometer(GameDataRef data) : _data(data)
	{
        _data->assets.LoadFont("Font", FONT_FILEPATH);
        _speedText.setFont(_data->assets.GetFont("Font"));
        // _speedText.se
	}

    
}