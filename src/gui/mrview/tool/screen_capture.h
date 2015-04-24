/*
   Copyright 2013 Brain Research Institute, Melbourne, Australia

   Written by David Raffelt 10/04/2013

   This file is part of MRtrix.

   MRtrix is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   MRtrix is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with MRtrix.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef __gui_mrview_tool_screen_capture_h__
#define __gui_mrview_tool_screen_capture_h__

#include "gui/mrview/tool/base.h"
#include "gui/mrview/adjust_button.h"

namespace MR
{
  namespace GUI
  {

    namespace MRView
    {
      class AdjustButton;

      namespace Tool
      {


        class Capture : public Base
        {
          Q_OBJECT
          public:
            Capture (Window& main_window, Dock* parent);
            virtual ~Capture() {}

            static void add_commandline_options (MR::App::OptionList& options);
            virtual bool process_commandline_option (const MR::App::ParsedOption& opt);

          private slots:
            void on_screen_capture ();
            void on_screen_preview ();
            void select_output_folder_slot();
            void on_output_update ();
            void on_trans_scanner_coords_slot (bool);

          private:

            AdjustButton *rotation_axis_x;
            AdjustButton *rotation_axis_y;
            AdjustButton *rotation_axis_z;
            AdjustButton *degrees_button;
            AdjustButton *translate_x;
            AdjustButton *translate_y;
            AdjustButton *translate_z;
            AdjustButton *target_volume;
            AdjustButton *FOV_multipler;
            QSpinBox *start_index;
            QSpinBox *frames;
            QSpinBox *volume_axis;
            QLineEdit *prefix_textbox;
            QPushButton *folder_button;
            int axis;
            QDir* directory;
            bool translate_in_scanner_coord;

            void run (bool with_capture);

        };

      }
    }
  }
}

#endif





