program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..4,1..40] of char;
   k,i,j:integer;
begin
   readln(k);
   for i:=1 to 11 do a[1,i]:='#';
   for i:=1 to 11 do a[2,i]:='#';
   a[3,1]:='#';
   for i:=1 to 11 do a[4,i]:='#';
   i:=1;
   j:=1;
   while k>0 do
      begin
         a[i,j]:='O';
         if  (i=1) then i:=2
         else if (j>1) and (i=2) then i:=4
         else if (j=1) and (i=2) then i:=3
         else if (i=3) then i:=4
         else
            begin
               inc(j);
               i:=1;
            end;
         dec(k);
      end;
   writeln('+------------------------+');
   write('|');
   for i:=1 to 11 do write(a[1,i],'.');
   writeln('|D|)');
   write('|');
   for i:=1 to 11 do write(a[2,i],'.');
   writeln('|.|');
   write('|');
   write(a[3,1]);
   writeln('.......................|');
   write('|');
   for i:=1 to 11 do write(a[4,i],'.');
   writeln('|.|)');
   writeln('+------------------------+');
   readln;
end.
