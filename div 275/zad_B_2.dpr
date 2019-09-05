program zad_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  cnt1,cnt2,x,y,l,r,m:int64;
function nod(a,b:int64):int64;
begin
   if (b=0) then nod:=a
   else nod:=nod(b,a mod b);
end;
function nok(a,b:int64):int64;
begin
    nok:=trunc(1.0*(a div nod(a,b))*b);
end;
function prov(m:int64):boolean;
  begin
    if(trunc(1.0*(m div x)*(x-1))+(m mod x)>=cnt1) and (trunc(1.0*(m div y)*(y-1))+(m mod y)>=cnt2)and (trunc(1.0*(m div y)* (y - 1)) + (m mod y) + trunc(1.0 * (m div x) * (x - 1)) + (m mod x) - (m - (m div x) - (m div y) + (m div nok(x, y))) >= cnt1 + cnt2) then
        prov:=true
      else
        prov:=false;
  end;
begin
  readln(cnt1, cnt2, x, y);
  l:=1;
  r:=2000000000000000000;
  while(l<r) do
     begin
        m:=(l+r) div 2;
        if(prov(m)) then r:=m
        else l:=m+1;
     end;
  writeln(r);
  readln;
end.
