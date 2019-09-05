program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,m,x1,y1,x2,y2,x3,y3,x4,y4:integer;
begin
   readln(n,m);
   x1:=0;
   y1:=0;
   x2:=n;
   y2:=m;
   if (1<=n) then
      begin
         x3:=1;
         y3:=0;
      end
   else
      begin
         x3:=0;
         y3:=1;
      end;
   if (n-1>=0) and ((n-1<>x1) or (m<>y1)) and ((n-1<>x2) or (m<>y2)) and ((n-1<>x3) or (m<>y3)) then
      begin
         x4:=n-1;
         y4:=m;
      end
   else
      begin
         x4:=n;
         y4:=m-1;
      end;
   writeln(x1,' ',y1);
   writeln(x2,' ',y2);
   writeln(x3,' ',y3);
   writeln(x4,' ',y4);
   readln;
end.
