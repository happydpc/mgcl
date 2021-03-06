/********************************************************************/
/* Copyright (c) 2011 DG Technologies Inc. and Yuzi Mizuno          */
/* All rights reserved.                                             */
/* Granted under the MIT license (see mg/MGCL.h for detail)         */
/********************************************************************/
#ifdef MGCL_NO_MFC
#include "mgGL/LineStippleNOMFC.h"
#else

#ifndef _MGLineStipple_HH_
#define _MGLineStipple_HH_

#include "mgGL/GLAttrib.h"

class MGOfstream;
class MGIfstream;

//
//Define MGLineStipple Class.

/** @addtogroup GLAttrib
 *  @{
 */

///MGLineStipple defines line stipple patters.
class MGCLASS MGLineStipple:public MGGLAttrib{

public:

enum LineFont{
	UndefinedFont=-1,
	///Solid=1,
	Dashed=2,		///<facotr=2, pattern=0x3333
	Phantom=3,		///<facotr=2, pattern=0x5757
	CenterLine=4,	///<facotr=2, pattern=0x5f5f
	Dotted=5		///<facotr=2, pattern=0x1111
};

MGLineStipple():MGGLAttrib(MGGLAttrib::UNDEFINED){;};
MGLineStipple(LineFont font);
MGLineStipple(int factor,unsigned short pattern)
:MGGLAttrib(factor){m_pattern=pattern;};

///Assignment
MGLineStipple& operator=(const MGGel& gel2);
MGLineStipple& operator=(const MGLineStipple& gel2);

///comparison
bool operator<(const MGLineStipple& gel2)const;
bool operator<(const MGGel& gel2)const;

////////////Member Function////////////

///Generate a newed clone object.
MGLineStipple* clone()const;

///Invoke appropriate OpenGL fucntion to this attribute.
void exec()const;

void set(int factor,unsigned short pattern){data()=factor;m_pattern=pattern;};
int get_factor()const{return data();};
unsigned short get_pattern()const{return m_pattern;};

///Get the font number
LineFont get_font_number()const;

///draw GLAttribute process.
void drawAttrib(
	bool no_color=false	///<if true, color attribute will be neglected.
)const{exec();};

///render GLAttribute process.
void render()const{exec();};

///Turn on the appropriate mask bit for this attribute. See glPushAttrib().
void set_draw_attrib_mask(unsigned int& mask)const{set_Amask(mask,LINE_BIT);};

///Turn off the appropriate mask bit for this attribute. See glPushAttrib().
void reset_draw_attrib_mask(unsigned int& mask)const{reset_Amask(mask,LINE_BIT);};

///Turn on the appropriate mask bit for this attribute. See glPushAttrib().
void set_render_attrib_mask(unsigned int& mask)const{set_Amask(mask,LINE_BIT);};

///Turn off the appropriate mask bit for this attribute. See glPushAttrib().
void reset_render_attrib_mask(unsigned int& mask)const{reset_Amask(mask,LINE_BIT);};

/// Return This object's typeID
long identify_type() const{return MGLINE_STIPPLE_TID;};

std::string whoami()const{return "LineStipple";};

///Read all member data.
void ReadMembers(MGIfstream& buf);
///Write all member data
void WriteMembers(MGOfstream& buf)const;

/// Output function.
std::ostream& out(std::ostream&) const;

private:
	unsigned short m_pattern;///<line stipple pattern.

};

/** @} */ // end of GLAttrib group
#endif //#ifndef _MGLineStipple_HH_
#endif //#ifdef MGCL_NO_MFC

