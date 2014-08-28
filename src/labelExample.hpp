#pragma once
/*
 * labelExample.hpp
 *
 *  Created on: Aug 27, 2014
 *      Author: nickhathaway
 */

#include <gtkmm.h>

class labelExample : public Gtk::Window
{
public:
	labelExample();
  virtual ~labelExample();

protected:

  //Child widgets:
  Gtk::Box m_HBox;
  Gtk::Box m_VBox, m_VBox2;
  Gtk::Frame m_Frame_Normal, m_Frame_Multi, m_Frame_Left, m_Frame_Right,
    m_Frame_LineWrapped, m_Frame_FilledWrapped, m_Frame_Underlined;
  Gtk::Label m_Label_Normal, m_Label_Multi, m_Label_Left, m_Label_Right,
    m_Label_LineWrapped, m_Label_FilledWrapped, m_Label_Underlined;
};




