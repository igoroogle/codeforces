program ZAD_B1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   n,i,j,p,mint,dd,x,s,m,z:integer;
   a:array [1..50] of integer;
function prov:integer;
var
   i,j,p,ss,mt:integer;
begin
   ss:=0;
   for i:=1 to n do
      for j:=i to n do
         begin
            mt:=maxint;
            for p:=i to j do
               if (a[p]<mt) then mt:=a[p];
            ss:=ss+mt;
         end;
   prov:=ss;
end;
begin
   read(n,m);
   s:=0;
   for i:=1 to n do a[i]:=i;
   while true do
      begin
         p:=n-1;
         while (p>0) and (a[p+1]<a[p]) do dec(p);
         z:=prov;
         if (z<s) then s:=z;
         if (p=0)  then break;
         mint:=p+1;
         for i:=p+2 to n do
            if (a[i]>a[p]) and (a[i]<a[mint]) then mint:=i;
         dd:=a[mint];
         a[mint]:=a[p];
         a[p]:=dd;
         for i:=p+2 to n do
            begin
               j:=i-1;
               x:=a[i];
               while (j>p) and (a[j]>x) do
                  begin
                     a[j+1]:=a[j];
                     dec(j);
                  end;
               a[j+1]:=x;
            end;
      end;
   for i:=1 to n do write(a[i],' ');
   readln;
   readln;
end.
