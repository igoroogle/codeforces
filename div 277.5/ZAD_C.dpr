program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type
    ar = array [0..110] of smallint;
var
   m,s,dd,i:integer;
   sum:int64;
   a,b:ar;
procedure writelong(var a:ar);
var
   i:integer;
begin
   for i:=a[0] downto 1 do write(a[i]);
end;
begin
   readln(m,s);
   if ((s=0) and (m>1)) or (9*m<s) then
      begin
         writeln(-1,' ',-1);
         readln;
         halt;
      end;
   if (s=0) then
      begin
         writeln(0,' ',0);
         readln;
         halt;
      end;
   a[0]:=m;
   b[0]:=m;
   for i:=1 to m do
      begin
         a[i]:=0;
         b[i]:=0;
      end;
   sum:=1;
   a[m]:=1;
   for i:=1 to m do
      begin
         if (s-(sum-a[i])<10) then
            begin
               dd:=a[i];
               a[i]:=s-(sum-dd);
               break;
            end
         else
            begin
               dd:=a[i];
               a[i]:=9;
               sum:=sum-dd+9;
            end;
      end;
   sum:=0;
   for i:=m downto 1 do
      begin
         if (s-sum<10) then
            begin
               b[i]:=s-sum;
               break;
            end
         else
            begin
               b[i]:=9;
               sum:=sum+9;
            end;
      end;
   writelong(a);
   write(' ');
   writelong(b);
   writeln;
   readln;
end.
