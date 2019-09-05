program ZAD_R;

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
function ppram(x,y,a,b,c:int64):boolean;
begin
   ppram:=trunc(1.0*a*x+1.0*b*y)+c=0;
end;
function potr(x,y,x1,y1,x2,y2:int64):boolean;
var
   a,b,c:int64;
begin
   pram(x1,y1,x2,y2,a,b,c);
   potr:=(trunc(1.0*(x-x1)*(x2-x1)+1.0*(y-y1)*(y2-y1))>=0) 
   and (trunc(1.0*(x-x2)*(x1-x2)+1.0*(y-y2)*(y1-y2))>=0) and (ppram(x,y,a,b,c));
end;
begin
   reset(input,'point3.in');
   rewrite(output,'point3.out');
   readln(x,y,x1,y1,x2,y2);
   if (potr(x,y,x1,y1,x2,y2)) then writeln('YES')
   else writeln('NO');
   readln;
end.
