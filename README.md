# cosine_taper_cpp
The cosine taper program in C++
# How to compile
There are two main program files of cosine taper. The first is **cosine_vector.cpp** and the second is **cosine_function.cpp**. The **cosine_vector.cpp** is the basic program without uisng header file/function file. Otherwise, the **cosine_function.cpp** is using header file to call the **costaper** function fom **window.h** header file.<br/><br/>

Type the following command in your terminal
```
g++ -o coswin_vector coswin_vector.cpp
```
and type
```
./coswin_vector
```
For cosine_function.cpp
```
g++ -o coswin_function coswin_function.cpp
```
and type
```
./coswin_function
```

to run the program. The program will produce three files:<br/> 1. coswin_signal.txt is the raw signal <br/> 2. coswinout.txt is the cosine taper window <br/> 3. coswin_combined.txt is the combination between raw signal and cosine taper <br/><br/> You can see the result in cosine_figure.png
# Source
Tapering of windowed time series (DOI: 10.2312/GFZ.NMSOP-2_IS_14.1)<br/>Marco Pilz and Stefano Parolai,Helmholtz Centre Potsdam, GFZ<br/>
http://gfzpublic.gfz-potsdam.de/pubman/faces/viewItemOverviewPage.jsp?itemId=escidoc:56141
# Contact
Email: auliakhalqillah.mail@gmail.com
