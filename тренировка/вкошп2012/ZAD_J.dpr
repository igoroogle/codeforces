program ZAD_J;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   r,l,dl,f,g,m,x1,y1,x2,y2,x,y:real;
   i:integer;
begin
   readln(r,l);
   if (l>2*r) then
      begin
         writeln(-r,' ',0,' ',r,' ',0);
         readln;
         halt;
      end;
   x1:=0;
   y1:=r;
   x2:=r;
   y2:=0;
   for i:=1 to 100 do
      begin
         m:=(f+g)/2;
         x:=x1+x2;
         y:=y1+y2;
         x:=x/()*l
      end;
   writeln(x1,' ',y1);
   writeln(x2,' ',y2);
   readln;
end.
