# 2-d Graph System

This is cpp language written program to simulate points and lines 
on the console mathematically (not graphically), and manipulating 
them  with some methods.

> Every Class have a method `to_string()` which gives a string form 
> of the Class (Point or Line).

> All the bugs in the `Line` class have been removed and is completely 
> bug free. Can be used freely without issues. 

## Classes
There are two classes defined in this project. They are:
1. Point
2. Line

### Point Class
The Point class consists all the manipulation methods and behaviour 
of a real-time point on a rectangular plane graph mathematically. 

**Attributes and Methods of Point Class**  
As the private members, both the abscissa (x co-ordinate) & ordinate 
(y co-ordinate) are defined as `m_x` and `m_y` (which are floats btw) 
referring the pair as `(m_x, m_y)`.  

As the members are private, they got getters when needed. 
`getX(), getY()` for getting the respective values of abscissa and 
ordinate.
Also some more methods down below:
1. `getQuadrant()`
2. `getDistanceFrom(Point P)` or `getDistanceTo(Point P)`
3. `getDistanceFromOrigin()`

All the methods are striaght-forward and behave as their names. 
The `getQuadrant()` method gives the qudrant of the Point.  
The `getDistanceFrom(Point P)` gives the distance between 
    the current point and the point passed as an arg.
The `getDistanceFromOrigin()` calculated the distance from Origin.

**Static methods of Point Class**  
The Point Class have a static method called `getOrigin()` which 
returns a point instance whose values are same as Origin. This 
is just to make sure the Single important Point of the entire graph 
system handy for program.

### Line Class
All (almost-all) the manipulation methods and attributes of a real-time 
are bundled in the Line class of the project. The Line class is known to 
create a line instance with two Points. We added almost anything we can do 
with Points and Lines. We have some good methods regarding calculations 
with Lines and Points.

**Constructers.**  
The Line Class have three constructers. 
```cpp
Line(Point, Point);         //  This creates a line instance from 2 Points.
Line(m_a, m_b, m_c);        //  This creates a line instance from 3 floats viz. the co-efficients.
Line(slope, y_intercept);   //  This creates a line instance from slope & y_intercept of the Line.
                            //+ (as a slope-intercept form).
```

**Attributes and Methods of Line Class**  
The co-efficients of the line ('a'X + 'b'Y + 'c' = 0) are stored as the 
private members of the instance which are necessary for the Line existance. 
Those private members are defined as `m_a`, `m_b`, `m_c`. We also have some 
other attributes for line. They are `slope`, `y_intercert`, `x_intercept`. 
Because no line would exists without these three things.  

All the above attricutes get computed as soon as the Line instance gets 
created. These attricutes also have getters:
```cpp
float getSlope();           // For slope
float getX_intercept();     // For X_intercept
float getY_intercept();     // For Y_intercept
```

**Some static methods of Line Class**  
We have some static methods of Line Class, they are:
1. `getX_axis()`
2. `getY_axis()`
3. `getLineFromPoints(Point p1, Point p2)`
4. `calcSlope(Point p1, Point p2)`

All the methods best-fit with their names, and those names almost tells 
what the methods do. `getX_axis(), getY_axis()` methods return a Line 
instance which are ***X & Y axes*** respectively. The `getLineFromPoints()` 
is same like the constructor with two Points input, it returns the Line 
instance of the Combination of 2 Points, And the `calcSlope(Point, Point)` 
is for calculating the slope of the Line formed by the two Points.  

The Line class also have much more line equation formatting funcitons 
to mathematically represent the lines:
1. `toString()`
    - Normal string representation of a line.
2. `toGeneralForm()`
    - Convert the line into General form and return a string of euqation of line.
3. `toSlopeForm()`
    - Convert the line into Slope form and return a string of euqation of line.

