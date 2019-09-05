program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x,y,minx,miny,maxx,maxy,n,i,max:integer;
begin
   read(n);
   minx:=maxint;
   miny:=maxint;
   maxx:=-maxint;
   maxy:=-maxint;
   for i:=1 to n do
      begin
         read(x,y);
         if (x>maxx) then maxx:=x;
         if (x<minx) then minx:=x;
         if (y>maxy) then maxy:=y;
         if (y<miny) then miny:=y;
      end;
   if (abs(maxx-minx)>abs(maxy-miny)) then max:=abs(maxx-minx)
   else max:=abs(maxy-miny);
   writeln(trunc(1.0*max*max));
   readln;
   readln;
end.
