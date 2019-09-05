program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  d,h:array [0..100010] of integer;
  i,n,m,mx,l,r,mm:integer;
begin
   read(n,m);
   mx:=0;
   d[0]:=0;
   h[0]:=0;
   for i:=1 to m do read(d[i],h[i]);
      begin
         if (abs(h[i]-h[i-1])>abs(d[i]-d[i-1])) then
            begin
               writeln('IMPOSSIBLE');
               readln;
               halt;
            end;
         l:=0;
         r:=d[i]-d[i-1];
         while (l<r) do
            begin
               mm:=(l+r) div 2;
               if (h[i-1]+mm-(h[i]+(d[i]-d[i-1])-mm)<=h[i]) then l:=mm+1
               else r:=mm;
            end;
         if (h[i-1]+l-(h[i]+(d[i]-d[i-1])-l)>h[i]) then dec(l);
         if (h[i-1]+l>mx) then mx:=h[i-1]+l;
      end;
   if (n-d[m]+h[i]>mx) then mx:=n-d[m]+h[i];
   writeln(mx);
   readln;
end.