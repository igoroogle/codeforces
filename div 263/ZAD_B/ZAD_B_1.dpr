program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;

var
   a:array [1..26] of integer;
   i,j,n,k,x:integer;
   s:int64;
   st:string;
begin
   //oo
   readln(n,k);
   readln(st);
   for i:=1 to 26 do a[i]:=0;
   for i:=1 to n do inc(a[ord(st[i])-64]);
   for i:=2 to 26 do
      begin
         x:=a[i];
         for j:=i-1 downto 1 do
            begin
               if (a[j]<x) then a[j+1]:=a[j]
               else begin a[j+1]:=x; break; end;
               if (j=1) then a[1]:=x;
            end;
      end;
   s:=0;
   for i:=1 to 26 do
      begin
         if (k>=a[i]) then
            begin
               s:=s+ trunc(power(a[i], 2));
               k:=k-a[i];
            end
         else
            begin
               s:=s+trunc(power(k, 2));
               break;
            end;
      end;
   writeln(s);
   readln;

   close(input);
   close(output);
end.
 