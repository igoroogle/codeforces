program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..6] of integer;
   i,j,a1,b1,x:integer;
begin
   read(a[1]);
   for i:=2 to 6 do
      begin
         read(x);
         j:=i-1;
         while (j>0) and (x<a[j]) do
            begin
               a[j+1]:=a[j];
               dec(j);
            end;
         a[j+1]:=x;
      end;
   a1:=-1;
   b1:=-1;
   if (a[1]=a[2]) and (a[1]=a[3]) and  (a[1]=a[4]) then
      begin
          a1:=a[5];
          b1:=a[6];
      end
   else if (a[2]=a[3]) and (a[2]=a[4]) and  (a[2]=a[5]) then
      begin
          a1:=a[1];
          b1:=a[6];
      end
   else if (a[3]=a[4]) and (a[3]=a[5]) and  (a[3]=a[6]) then
      begin
          a1:=a[1];
          b1:=a[2];
      end;
   if (a1=-1) then writeln('Alien')
   else if (a1<>b1) then writeln('Bear')
   else writeln('Elephant');
   readln;
   readln;
end.
