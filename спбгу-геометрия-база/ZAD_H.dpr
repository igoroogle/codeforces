program ZAD_H;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x,y,x1,y1,x2,y2:int64;
procedure pram(x1,y1,x2,y2:int64; var a,b,c:int64);
begin
   a:=y1-y2;
   b:=x2-x1;
   c:=-trunc(1.0*a*x1+1.0*b*y1);
end;
function ras_luch(x,y,x1,y1,x2,y2:int64):extended;
var
   a,b,c:int64;
begin
   pram(x1,y1,x2,y2,a,b,c);
   if (trunc(1.0*(x-x1)*(x2-x1)+1.0*(y-y1)*(y2-y1))<=0) then
      ras_luch:=sqrt(1.0*(x-x1) * (x-x1) + 1.0*(y-y1) * (y-y1))
   else ras_luch:=abs(trunc(1.0*a*x+1.0*b*y)+c)/sqrt(1.0*a*a+1.0*b*b);
end;
begin
   reset(input,'distance3.in');
   rewrite(output,'distance3.out');
   readln(x,y,x1,y1,x2,y2);
   writeln(ras_luch(x,y,x1,y1,x2,y2));
   readln;
end.
