program ZAD_T;
 
{$APPTYPE CONSOLE}
 
uses
  SysUtils;

const
   eps = 1e-9;
var
   x1,y1,x2,y2,x3,y3,x4,y4:int64;
   r1,r2,r3,r4,r:extended;
function luch (x,y,x1,y1,x2,y2:int64):boolean;
var
   a,b,c:int64;
begin
   a:=y1-y2;
   b:=x2-x1;
   c:=-trunc(1.0*a*x1+b*y1);
   luch:=(trunc(1.0*(x-x1)*(x2-x1) + 1.0 * (y-y1) * (y2-y1)) >= 0) and
  ( trunc(1.0*a * x + 1.0 * b * y ) + c =0);
end;
function pram (x,y,a,b,c:int64):int64;
var
   t:int64;
begin
   t:=trunc(1.0 * a * x + 1.0 * b * y) + c;
   if (t<0) then pram:=-1
   else if (t>0) then pram:=1
   else pram:=0;
end;
function luchper(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2:int64):boolean;
var
   a1,b1,c1,a2,b2,c2,a3,b3,c3,t1,t2:int64;
   xk,yk,z:extended;
begin
   if ((luch(ax1,ay1,bx1,by1,bx2,by2)) or (luch(bx1,by1,ax1,ay1,ax2,ay2)) or
   ((luch(ax2,ay2,bx1,by1,bx2,by2)) or (luch(bx2,by2,ax1,ay1,ax2,ay2)))) then
      begin
         luchper:=true;
         exit;
      end;
   a1:=ay1-ay2;
   b1:=ax2-ax1;
   c1:=-trunc(1.0*a1 *ax1+1.0 * b1 * ay1);
   a2:=by1-by2;
   b2:=bx2-bx1;
   c2:=-trunc(1.0*a2 *bx1+1.0 * b2 * by1);
   a3:=ay1-by1;
   b3:=bx1-ax1;
   c3:=-trunc(1.0*a3 *ax1+1.0 * b3 * ay1);
   if (trunc(1.0*a1*b2) = trunc(1.0*a2*b1)) then
      begin
         luchper:=false;
         exit;
      end;
   if ((pram(ax2,ay2,a3,b3,c3)=0) or (pram(bx2,by2,a3,b3,c3)=0) or
    (pram(ax2,ay2,a3,b3,c3)<>pram(bx2,by2,a3,b3,c3))) then
      begin
         luchper:=false;
         exit;
      end;
   t1:=pram(ax2,ay2,a3,b3,c3);
   z:=1.0*a1*b2-1.0*a2*b1;
   if (z=0) then z:=eps;
   xk:=(1.0*b1*c2 - 1.0*b2*c1) / z;
   yk:=(1.0*c1*a2 - 1.0*c2*a1) / z;
   if (xk*a3+yk*b3+c3<0) then t2:=-1
   else t2:=1;
   luchper:=t1=t2;
end;
procedure pram2(x1,y1,x2,y2:int64; var a,b,c:int64);
begin
   a:=y1-y2;
   b:=x2-x1;
   c:=-trunc(1.0*a*x1+1.0*b*y1);
end;
function ras_luch(x,y,x1,y1,x2,y2:int64):extended;
var
   a,b,c:int64;
begin
   pram2(x1,y1,x2,y2,a,b,c);
   if (trunc(1.0*(x-x1)*(x2-x1)+1.0*(y-y1)*(y2-y1))<=0) then
      ras_luch:=sqrt(1.0*(x-x1) * (x-x1) + 1.0*(y-y1) * (y-y1))
   else ras_luch:=abs(trunc(1.0*a*x+1.0*b*y)+c)/sqrt(1.0*a*a+1.0*b*b);
end;
begin
   reset(input,'raydist.in');
   rewrite(output,'raydist.out');
   readln(x1,y1,x2,y2,x3,y3,x4,y4);
   r1:=ras_luch(x1,y1,x3,y3,x4,y4);
   r2:=ras_luch(x2,y2,x3,y3,x4,y4);
   r3:=ras_luch(x3,y3,x1,y1,x2,y2);
   r4:=ras_luch(x4,y4,x1,y1,x2,y2);
   if (r1<r2) then r:=r1
   else r:=r2;
   if (r3<r) then r:=r3;
   if (r4<r) then r:=r4;
   if (luchper(x1,y1,x2,y2,x3,y3,x4,y4)) then r:=0;
   writeln(r);
   readln;
end.
