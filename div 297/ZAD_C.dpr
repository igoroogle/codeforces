program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
   dl = 1000010;
var
   a:array [1..dl] of integer;
   b:array [1..dl] of int64;
   n,x,i,j,kol:integer;
   s:int64;
begin
   read(n);
   for i:=1 to dl do a[i]:=0;
   for i:=1 to n do
      begin
         read(x);
         inc(a[x]);
      end;
   s:=0;
   kol:=1;
   for i:=dl downto 1 do
      for j:=1 to a[i] do
         begin
            if (odd(kol)) then
               begin
                  b[kol]:=i;
                  inc(kol);
               end
            else if (i=b[kol-1]) then
               begin
                  b[kol]:=i;
                  inc(kol);
               end
            else if (i+1=b[kol-1]) then
               begin
                  b[kol-1]:=i;
                  b[kol]:=i;
                  inc(kol);
               end
            else
               begin
                  dec(kol);
                  b[kol]:=i;
               end;
         end;
   dec(kol);
   if (odd(kol)) then dec(kol);
   if (kol mod 4 <> 0) then dec(kol,2);
   i:=1;
   while (i+3<=kol) do
      begin
         s:=s+trunc(1.0*b[i]*b[i+2]);
         inc(i,4);
      end;
   writeln(s);
   readln;
   readln;
end.