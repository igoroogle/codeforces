program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [0..9] of integer;
   s:string;
   n,i,j:integer;
begin
   readln(n);
   readln(s);
   for i:=0 to 9 do a[i]:=0;
   for i:=1 to n do
      begin
         case s[i] of
            '2':inc(a[2]);
            '3':inc(a[3]);
            '4':
                begin
                   a[2]:=a[2]+2;
                   inc(a[3]);
                end;
            '5':inc(a[5]);
            '6':
                begin
                   inc(a[3]);
                   inc(a[5]);
                end;
            '7':inc(a[7]);
            '8':
                begin
                   a[2]:=a[2]+3;
                   inc(a[7]);
                end;
            '9':
                begin
                   a[3]:=a[3]+2;
                   inc(a[2]);
                   inc(a[7]);
                end;
         end;
      end;
   for i:=9 downto 2 do
      for j:=1 to a[i] do write(i);
   writeln;
   readln;
end.
