program ZAD_L;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x1,y1,x2,y2:extended;
begin
   reset(input,'length.in');
   rewrite(output,'length.out');
   readln(x1,y1,x2,y2);
   writeln(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)):1:6);
end.
