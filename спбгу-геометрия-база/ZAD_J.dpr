program ZAD_J;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x1,y1,x2,y2,x3,y3,x4,y4:int64;
   r1,r2,r3,r4,r:extended;
function sotr(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2:int64):boolean;
var
   v1,v2,v3,v4:int64;
begin
   v1:=trunc(1.0*(ax1-bx1)*(ay2-by1)-1.0*(ax2-bx1)*(ay1-by1));
   v2:=trunc(1.0*(ax1-bx2)*(ay2-by2)-1.0*(ax2-bx2)*(ay1-by2));
   v3:=trunc(1.0*(bx1-ax1)*(by2-ay1)-1.0*(bx2-ax1)*(by1-ay1));
   v4:=trunc(1.0*(bx1-ax2)*(by2-ay2)-1.0*(bx2-ax2)*(by1-ay2));
   sotr:=(trunc(1.0*v1*v2)<0) and (trunc(1.0*v3*v4)<0);
end;
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
function ras_otr(x,y,x1,y1,x2,y2:int64):extended;
var
   a,b,c:int64;
begin
   pram(x1,y1,x2,y2,a,b,c);
   if (trunc(1.0*(x-x1)*(x2-x1)+1.0*(y-y1)*(y2-y1))<=0) then
      ras_otr:=sqrt(1.0*(x-x1) * (x-x1) + 1.0*(y-y1) * (y-y1))
   else if (trunc(1.0*(x-x2)*(x1-x2)+1.0*(y-y2)*(y1-y2))<=0) then
      ras_otr:=sqrt(1.0*(x-x2) * (x-x2) + 1.0*(y-y2) * (y-y2))
   else ras_otr:=abs(trunc(1.0*a*x+1.0*b*y)+c)/sqrt(1.0*a*a+1.0*b*b);
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
   reset(input,'distance5.in');
   rewrite(output,'distance5.out');
   readln(x1,y1,x2,y2,x3,y3,x4,y4);
   r1:=ras_otr(x1,y1,x3,y3,x4,y4);
   r2:=ras_otr(x2,y2,x3,y3,x4,y4);
   r3:=ras_otr(x3,y3,x1,y1,x2,y2);
   r4:=ras_otr(x4,y4,x1,y1,x2,y2);
   if (r1<r2) then r:=r1
   else r:=r2;
   if (r3<r) then r:=r3;
   if (r4<r) then r:=r4;
   if (sotr(x1,y1,x2,y2,x3,y3,x4,y4)) or (potr(x1,y1,x3,y3,x4,y4))
   or (potr(x2,y2,x3,y3,x4,y4))
   or (potr(x3,y3,x1,y1,x2,y2))
   or (potr(x4,y4,x1,y1,x2,y2)) then r:=0;
   writeln(r);
   readln;
end.
