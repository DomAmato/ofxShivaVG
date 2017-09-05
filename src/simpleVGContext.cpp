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


#include "simpleVGContext.h"

simpleVGContext::simpleVGContext()
:_hasContext(false)
{
    
}

void simpleVGContext::create(VGint w, VGint h) const
{
    _hasContext = vgCreateContextSH(w, h);
    vgSeti(VG_RENDERING_QUALITY, VG_RENDERING_QUALITY_BETTER);
}


void simpleVGContext::setFillColor(VGint r, VGint g, VGint b, VGint a) const
{
    setFillColor(r/255.0f, g/255.0f, b/255.0f, a/255.0f);
}

void simpleVGContext::setFillColor(VGfloat r, VGfloat g, VGfloat b, VGfloat a) const
{
    if (_fillPaint) vgDestroyPaint(_fillPaint);
    
    VGfloat color[] = {r, g, b, a};
    _fillPaint = vgCreatePaint();
    vgSetParameterfv(_fillPaint, VG_PAINT_COLOR, 4, color);
    vgSetPaint(_fillPaint, VG_FILL_PATH);
}

void simpleVGContext::setStrokeColor(VGint r, VGint g, VGint b, VGint a) const
{
    setStrokeColor(r/255.0f, g/255.0f, b/255.0f, a/255.0f);
}

void simpleVGContext::setStrokeColor(VGfloat r, VGfloat g, VGfloat b, VGfloat a) const
{
    if (_strokePaint) vgDestroyPaint(_strokePaint);
    
    VGfloat color[] = {r, g, b, a};
    _strokePaint = vgCreatePaint();
    vgSetParameterfv(_strokePaint, VG_PAINT_COLOR, 4, color);
    vgSetPaint(_strokePaint, VG_STROKE_PATH);
}

void simpleVGContext::setStrokeWidth(VGfloat w) const
{
    _strokeWidth = w;
    vgSeti(VG_STROKE_LINE_WIDTH, w);
}

VGfloat simpleVGContext::getStrokeWidth() const
{
    return _strokeWidth;
}

void simpleVGContext::setStrokeJoinStyle(VGJoinStyle join) const
{
    _strokeJoinStyle = join;
    vgSeti(VG_STROKE_JOIN_STYLE, join);
}

void simpleVGContext::setStrokeCapStyle(VGCapStyle cap) const
{
    _strokeCapStyle = cap;
    vgSeti(VG_STROKE_CAP_STYLE, cap);
}

VGCapStyle simpleVGContext::getStrokeCapStyle() const
{
    return _strokeCapStyle;
}

VGJoinStyle simpleVGContext::getStrokeJoinStyle() const
{
    return _strokeJoinStyle;
}

void simpleVGContext::fillPath(simpleVGPath &path) const
{
    vgDrawPath(path.getVGPath(), VG_FILL_PATH);
}

void simpleVGContext::strokePath(simpleVGPath &path) const
{
    vgDrawPath(path.getVGPath(), VG_STROKE_PATH);
}


simpleVGContext::~simpleVGContext()
{
    if (_hasContext)
    {
        vgDestroyContextSH();
    }
}
