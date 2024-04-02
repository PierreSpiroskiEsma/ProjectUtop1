#include "Item.h"





bool Item::get_Is_Visible()
{
	return Is_Visible;
}

void Item::set_Is_Visible(bool visible)
{

	Is_Visible = visible;
}

bool Item::get_is_Possesd()
{
	return is_Possesd;
}

void Item::set_is_Possesd(bool possess)
{
	is_Possesd = possess;
}
