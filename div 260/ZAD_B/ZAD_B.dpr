program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [0..100010] of int64;
   s:string;
   i:integer;
   x:int64;
begin
   readln(s);
   a[0]:=0;
   for i:=length(s) downto 1 do
      begin
         inc(a[0]);
         a[a[0]]:=ord(s[i])-48;
      end;
   x:=0;
   for i:=a[0] downto 1 do
      x:=(x*10+a[i]) mod 4;
   if (x=0) or (x=4) then writeln(4)
   else writeln(0);
   readln;
end.
