program ZAD_C_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   c,hr,hb,wr,wb,sum,mx,ost,kol,z:int64;
   i:integer;
   v1,v2:extended;
procedure swap(var a,b:int64);
var
   c:int64;
begin
   c:=a;
   a:=b;
   b:=c;
end;
begin
   readln(c,hr,hb,wr,wb);
   v1:=hr/wr;
   v2:=hb/wb;
   if (v1>=v2) and (wr<=wb) then
      begin
         writeln(trunc(1.0 * (c div wr) * hr));
         readln;
         halt;
      end
   else if (v2>=v1) and (wb<=wr) then
      begin
         writeln(trunc(1.0 * (c div wb) * hb));
         readln;
         halt;
      end;
   if (wr>wb) then
      begin
         swap(wr,wb);
         swap(hr,hb);
      end;
   kol:=c div wb;
   sum:=trunc(1.0*kol*hb);
   ost:=c mod wb;
   sum:=sum + trunc(1.0 * (ost div wr) * hr);
   ost:=ost mod wr;
   z:=0;
   if (kol>0) then z:=sum-hb+(trunc(1.0 * ((ost+wb) div wr) * hr));
   mx:=sum;
   for i:=kol downto 1  do
      begin
         ost:=(ost+wb) mod wr;
         sum:=z;
         if (kol>0) then z:=sum-hb+(trunc(1.0*((ost+wb) div wr) * hr));
         if (sum>mx) then mx:=sum;
      end;
   if (sum>mx) then mx:=sum;
   writeln(mx);
   readln;
end.
