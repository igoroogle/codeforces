program ZAD_O;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b,c,r:int64;
   c1,c2,x,y:extended;
begin
   reset(input,'line3.in');
   rewrite(output,'line3.out');
   readln(a,b,c,r);
   if (b<>0) then
      begin
         x:=0;
         y:=(1.0*r*sqrt(1.0*a*a+1.0*b*b)-c)/b;
         r:=-r;
         c1:=-(1.0*a*x+1.0*b*y);
         x:=0;
         y:=(1.0*r*sqrt(1.0*a*a+1.0*b*b)-c)/b;
         c2:=-(1.0*a*x+1.0*b*y);
      end
   else
      begin
         y:=0;
         x:=(1.0*r*sqrt(1.0*a*a+1.0*b*b)-c)/a;
         r:=-r;
         c1:=-(1.0*a*x+1.0*b*y);
         y:=0;
         x:=(1.0*r*sqrt(1.0*a*a+1.0*b*b)-c)/a;
         c2:=-(1.0*a*x+1.0*b*y);
      end;
   writeln(a,' ',b,' ',c1);
   writeln(a,' ',b,' ',c2);
   readln;
end.
