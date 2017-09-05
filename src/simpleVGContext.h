/*
 * ofxShivaVG
 * A 2d rendering library for openFrameworks, based on the ShivaVG library
 * by Bjørn Gunnar Staal
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library in the file COPYING;
 * if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef __ofxShivaVG__SimpleVG__
#define __ofxShivaVG__SimpleVG__

#include "openvg.h"
#include "simpleVGPath.h"

class simpleVGContext
{
    public:
        simpleVGContext();
        ~simpleVGContext();
    
        void create(VGint w, VGint h) const;
    
        void setFillColor(VGint r, VGint g, VGint b, VGint a) const;
        void setFillColor(VGfloat r, VGfloat g, VGfloat b, VGfloat a) const;
        void setStrokeWidth(VGfloat w) const;
        void setStrokeCapStyle(VGCapStyle cap) const;
        void setStrokeJoinStyle(VGJoinStyle join) const;
        void setStrokeColor(VGint r, VGint g, VGint b, VGint a) const;
        void setStrokeColor(VGfloat r, VGfloat g, VGfloat b, VGfloat a) const;
        VGfloat getStrokeWidth() const;
        VGCapStyle getStrokeCapStyle() const;
        VGJoinStyle getStrokeJoinStyle() const;
    
        void fillPath(simpleVGPath &path) const;
        void strokePath(simpleVGPath &path) const;
    
    private:
    
        mutable bool _hasContext;
        mutable VGPaint _fillPaint = 0;
        mutable VGPaint _strokePaint = 0;
        mutable VGfloat _strokeWidth;
        mutable VGCapStyle _strokeCapStyle;
        mutable VGJoinStyle _strokeJoinStyle;
};

#endif
