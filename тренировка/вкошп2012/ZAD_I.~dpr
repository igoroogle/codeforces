program ZAD_I;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   less,more:array [0..9,0..9] of boolean;
   use:array [0..9] of boolean;
   a:array [1..11] of string;
   c,d:array [0..11] of integer;
   i,j,p,n,kol:integer;
   f:boolean;
begin
   //reset(input,'tiv.in');
   //assign(output,'tiv.out');
   for i:=0 to 9 do use[i]:=true;
   for i:=0 to 9 do
      for j:=0 to 9 do
         begin
            less[i,j]:=false;
            more[i,j]:=false;
         end;
   readln(n);
   for i:=1 to n do
      begin
         readln(a[i]);
         for j:=1 to i-1 do
            if (length(a[i])=length(a[j])) then
               begin
                  for p:=1 to length(a[i]) do
                     if (a[i][p]<>a[j][p]) then
                        begin
                           less[ord(a[i][p])-97,ord(a[j][p])-97]:=true;
                           more[ord(a[j][p])-97,ord(a[i][p])-97]:=true;
                           break;
                        end;
               end;
      end;
   {for i:=0 to 9 do
      for j:=0 to 9 do writeln(i,' ',j,' ',less[i,j]);
   writeln('--------');
   for i:=0 to 9 do
      for j:=0 to 9 do writeln(i,' ',j,' ',more[i,j]);
   readln;
   halt;}
   p:=0;
   for i:=2 to n do
      if (length(a[i-1])>length(a[i])) or (a[i]=a[i-1]) then
         begin
            writeln('No');
            readln;
            halt;
         end;
   for i:=0 to 9 do
      for j:=0 to 9 do
         if (less[i,j]) and (more[i,j]) then
            begin
               writeln('No');
               readln;
               halt;
            end;
   for kol:=9 downto 0 do
      begin
         for i:=0 to 9 do
            if  (use[i]) then
               begin
                  f:=true;
                  p:=i;
                  while (f) do
                     begin
                        f:=false;
                        for j:=0 to 9 do
                           if (more[p,j]) and (use[j]) then
                              begin
                                 p:=j;
                                 f:=true;
                                 break;
                              end;
                     end;
                  break;
               end;
         c[kol]:=p;
         use[p]:=false;
      end;
   for i:=0 to 9 do d[c[i]]:=i;
   //for i:=1 to 10 do d[i]:=c[i];
   for i:=1 to n do
      if (length(a[i])>1) and (ord(a[i][1])-48=d[0]) then
         begin
            writeln('No');
            readln;
            halt;
         end;
   writeln('Yes');
   for i:=0 to 8 do write(d[i],' ');
   writeln(d[9]);
   readln;
end.
