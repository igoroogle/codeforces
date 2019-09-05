program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   sum,sp:array [1..500010] of int64;
   r,x,s:int64;
   i,n:integer;
begin
   s:=0;
   readln(n);
   for i:=1 to n do
      begin
         read(x);
         s:=s+x;
         sum[i]:=s;
      end;
   if (s mod 3 <>0) then r:=0
   else
      begin
         x:=s div 3;
         s:=0;
         for i:=n downto 2 do
            begin
               if (sum[n]-sum[i-1]=x) then inc(s);
               sp[i]:=s;
            end;
         r:=0;
         for i:=1 to n-2 do
            if (sum[i]=x) then r:=r+sp[i+2];
      end;
   writeln(r);
   readln;
end.
 