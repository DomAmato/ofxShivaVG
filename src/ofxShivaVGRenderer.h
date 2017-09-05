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


#ifndef __ofxShivaVG__ofxShivaVGRenderer__
#define __ofxShivaVG__ofxShivaVGRenderer__

#include "ofMain.h"
#include "simpleVGContext.h"

class ofxShivaVGRenderer : public ofGLRenderer
{
    public:
    
        ofxShivaVGRenderer();
    
        void background(const ofColor & c);
        void clear(float r, float g, float b, float a=0);
        void clear(float brightness, float a=0);

        void draw(const ofPolyline & poly) const;
        void draw(const ofPath & path) const;
        void drawCircle(float x, float y, float z,  float radius) const;
        void drawEllipse(float x, float y, float z, float width, float height) const;
        void drawLine(float x1, float y1, float z1, float x2, float y2, float z2) const;
        void setLineCapStyle(VGCapStyle cap) const;
        void setLineJoinStyle(VGJoinStyle join) const;
        VGCapStyle getLineCapStyle() const;
        VGJoinStyle getLineJoinStyle() const;
    
    private:
    
        mutable simpleVGContext _vg;
        mutable deque<ofPoint> _curvePoints;
        mutable ofFloatColor _bgColor;
    
        void _doDrawPath(const ofPath & path, simpleVGPath & toPath) const;
    
};

#endif
