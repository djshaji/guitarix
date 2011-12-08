/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
 * Copyright (C) 2011 Pete Shorthose
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
* ---------------------------------------------------------------------------
*
*    This file is a part ofthe gx_head interface builder
*    and build the stereo effect rack,
*    it's a part of the class GxMainInterface
*
* ----------------------------------------------------------------------------
*/


#include "guitarix.h"         // NOLINT

#include <glibmm/i18n.h>      // NOLINT

// -------- the gx_head user interface build instruktions

namespace gx_gui {

void GxMainInterface::gx_build_stereo_rack() {
    openHorizontalTableBox("");
    gx_engine::PluginList& pl = engine.pluginlist;
    fStereoRackContainer = fBox[fTop];
    {
        // add controllers without show them
        openHorizontalhideBox("");
        {
            create_small_rackknob("jconv.balance");
            create_small_rackknob("jconv.diff_delay");
            create_small_rackknob("jconv.gain");
            create_small_rackknob("jconv.wet_dry");
            create_hslider("amp.balance", "balance");
        }
        closeBox();

        // ----- chorus
        openStereoRackBox(_("chorus"), pl.pos_var("chorus"), "chorus.on_off", "ui.Chorus");
        {
            openHorizontalBox("");
            {
                create_small_rackknobr("chorus.level", _("  level  "));
                create_small_rackknob("chorus.delay", _("  delay  "));
                create_small_rackknob("chorus.depth", _("  depth  "));
                create_small_rackknob("chorus.freq", _("  freq  "));
            }
            closeBox();
        }
        closeStereoRackBox();
        // flanger
        openStereoRackBox(_("flanger"), pl.pos_var("flanger"), "flanger.on_off", "ui.Flanger");
        {
            openHorizontalBox("");
            {
                openHorizontalBox("");
                {
                    create_small_rackknobr("flanger.level", _("  level  "));
                }
                closeBox();
                openVerticalBox("");
                {
                    openHorizontalBox("");
                    {
                        create_small_rackknob("flanger.feedback gain", _(" feedback "));
                        create_small_rackknob("flanger.depth", _("  depth  "));
                        create_small_rackknob("flanger.flange delay", _("  delay  "));
                        create_small_rackknob("flanger.flange delay offset", _(" delay offset"));
                        create_small_rackknob("flanger.LFO freq", _(" LFO "));
                    }
                    closeBox();
                    openSpaceBox("");
                    closeBox();
                    openHorizontalBox("");
                    {
                        openSpaceBox("");
                        closeBox();
                        create_selector("flanger.invert");
                        openSpaceBox("");
                        closeBox();
                        openSpaceBox("");
                        closeBox();
                        openSpaceBox("");
                        closeBox();
                        openSpaceBox("");
                        closeBox();
                        openSpaceBox("");
                        closeBox();
                        openSpaceBox("");
                        closeBox();
                    }
                    closeBox();
                    openFrameBox("");
                    closeBox();
                }
                closeBox();
            }
            closeBox();
        }
        closeStereoRackBox();
        // phaser
        openStereoRackBox(_("phaser"), pl.pos_var("phaser"), "phaser.on_off", "ui.Phaser");
        {
            openHorizontalBox("");
            {
                openHorizontalBox("");
                {
                    create_small_rackknobr("phaser.level", _("  level "));
                }
                closeBox();
                openVerticalBox("");
                {
                    openHorizontalBox("");
                    {
                        create_small_rackknob("phaser.feedback gain", _(" feedback "));
                        create_small_rackknob("phaser.depth", _("depth"));
                        create_small_rackknob("phaser.Notch width", _("width"));
                        create_small_rackknob("phaser.NotchFreq", _("freq"));
                        create_small_rackknob("phaser.MaxNotch1Freq", _("max Hz"));
                        create_small_rackknob("phaser.MinNotch1Freq", _("min Hz"));
                        create_small_rackknob("phaser.Speed", _("speed"));
                    }
                    closeBox();
                    openSpaceBox("");
                    closeBox();
                    openHorizontalBox("");
                    {
                        openSpaceBox("");
                        closeBox();
                        create_selector("phaser.invert");
                        openSpaceBox("");
                        closeBox();
                        create_selector("phaser.VibratoMode");
                        openSpaceBox("");
                        closeBox();
                        openSpaceBox("");
                        closeBox();
                        openSpaceBox("");
                        closeBox();
                        openSpaceBox("");
                        closeBox();
                        openSpaceBox("");
                        closeBox();
                    }
                    closeBox();
                    openFrameBox("");
                    closeBox();
                }
                closeBox();
            }
            closeBox();
        }
        closeStereoRackBox();
        // stereo delay
        openStereoRackBox(_("delay"), pl.pos_var("stereodelay"), "stereodelay.on_off", "ui.Stereo Delay");
        {
            openHorizontalBox("");
            {
                create_small_rackknob("stereodelay.l_gain", _("left gain"));
                create_small_rackknob("stereodelay.l_delay", _("left delay"));
                openVerticalBox("");
                {
                    create_small_rackknobr("stereodelay.LFO freq", _("LFO"));
                    openSpaceBox("");
                    closeBox();
                    create_selector("stereodelay.invert");
                    openFrameBox("");
                    closeBox();
                }
                closeBox();
                create_small_rackknob("stereodelay.r_gain", _("right gain"));
                create_small_rackknob("stereodelay.r_delay", _("right delay"));
            }
            closeBox();
        }
        closeStereoRackBox();
        // echo
        openStereoRackBox(_("echo"), pl.pos_var("stereoecho"), "stereoecho.on_off", "ui.Stereo Echo");
        {
            openHorizontalBox("");
            {
                create_small_rackknob("stereoecho.percent_l", _("left %"));
                create_small_rackknob("stereoecho.time_l", _("left time"));
                create_small_rackknob("stereoecho.percent_r", _("right %"));
                create_small_rackknob("stereoecho.time_r", _("right time"));
            }
            closeBox();
        }
        closeStereoRackBox();
        // moog filter
        openStereoRackBox(_("moog"), pl.pos_var("moog"), "moog.on_off", "ui.Moog Filter");
        {
            openHorizontalTableBox("");
            {
                create_small_rackknob("moog.Q", _("            Q            "));
                create_small_rackknob("moog.fr", _("            Hz           "));
            }
            closeBox();
        }
        closeStereoRackBox();
        // postamp
        openStereoRackBox(_("amp"), pl.pos_var("ampmodul"), "ampmodul.on_off", "ui.Postamp");
        {
            openHorizontalBox("");
            {
                openSpaceBox("");
                closeBox();
                create_small_rackknobr("ampmodul.feedbac", _("dry/feedback  "));
                create_small_rackknob("ampmodul.wet_dry", _("dry/wet"));
                create_small_rackknob("ampmodul.level", _("level"));
                create_small_rackknob("ampmodul.amp2.stage1.tube1", _("tube1"));
                create_small_rackknob("ampmodul.amp2.stage2.tube2", _("tube2"));
                create_small_rackknobr("ampmodul.feedback", _("  wet/feedback"));
                openSpaceBox("");
                closeBox();
            }
            closeBox();
        }
        closeStereoRackBox();
        // 3 band eq
        openStereoRackBox(_("tone"), pl.pos_var("tonemodul"), "tonemodul.on_off", "ui.3 Band EQ");
        {
            openHorizontalBox("");
            {
                create_small_rackknob("tonemodul.Bass", _("bass"));
                create_small_rackknob("tonemodul.Middle", _("middle"));
                create_small_rackknob("tonemodul.Treble", _("treble"));
                openSpaceBox("");
                closeBox();
                create_switch_no_caption(sw_switchit, "tonemodul.ON");
                create_small_rackknob("tonemodul.sharper", _("sharp"));
            }
            closeBox();
        }
        closeStereoRackBox();
        
        openStereoRackBox(_("convolver"), pl.pos_var("jconv"), "jconv.on_off", "ui.Convolver");
        {
            openHorizontalBox("");
            {
                openVerticalBox("");
                {
                openSetLabelBox();
                {
                }
                closeBox();
                openHorizontalBox("");
                {
                    openSpaceBox("");
                    closeBox();
                    openSpaceBox("");
                    closeBox();
                    create_small_rackknobr("jconv.gain", _("gain"));
                    openSpaceBox("");
                    closeBox();
                    create_small_rackknob("jconv.diff_delay", _("delta delay"));
                    openSpaceBox("");
                    closeBox();
                    create_small_rackknob("jconv.balance", _("balance"));
                    openSpaceBox("");
                    closeBox();
                    create_small_rackknobr("jconv.wet_dry", _("dry/wet"));
                    openSpaceBox("");
                    closeBox();
                    openSpaceBox("");
                    closeBox();
                }
                closeBox();
                }
                closeBox();
                openSpaceBox("");
                closeBox();
                openVerticalBox("");
                {
                    openSpaceBox("");
                    closeBox();
                    addJConvFavButton(_("favourites"));
                    addJConvButton(_("setup"), &gx_engine::audio.filebutton);
                    addJToggleButton(_("run"), &engine.convolver.plugin.on_off);
                    openSpaceBox("");
                    closeBox();
                }
                closeBox();
            }
            closeBox();
        }
        closeStereoRackBox();
        //stereoverb
        openStereoRackBox(_("stereoverb"), pl.pos_var("stereoverb"), "stereoverb.on_off", "ui.Stereo Verb");
        {
            openHorizontalBox("");
            {
                create_small_rackknobr("stereoverb.RoomSize", _("RoomSize"));
                create_small_rackknob("stereoverb.damp", _("damp"));
                create_small_rackknob("stereoverb.wet_dry", _("dry/wet"));
            }
            closeBox();
        }
        closeStereoRackBox();
        
        openHorizontalhideBox1("");
        {
            create_hslider("amp.balance", "balance");
        }
        closeBox();
    }
    closeBox();
}   // close stereo rack
}  // end namespace gx_gui
