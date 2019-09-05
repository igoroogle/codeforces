program ZAD_I_8;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   less,more:array [0..9,0..9] of boolean;
   nul,use:array [0..9] of boolean;
   a:array [1..11] of string;
   c,d,last,next:array [0..9] of integer;
   i,j,p,n,kol:integer;
   f:boolean;
begin
   reset(input,'tiv.in');
   assign(output,'tiv.out');
   for i:=0 to 9 do
      for j:=0 to 9 do
         begin
            less[i,j]:=false;
            more[i,j]:=false;
         end;
   for i:=0 to 9 do
      begin
         nul[i]:=true;
         use[i]:=true;
         last[i]:=0;
         next[i]:=0;
      end;
   readln(n);
   for i:=1 to n do
      begin
         readln(a[i]);
         if (length(a[i])>1) then nul[ord(a[i][1])-97]:=false;
         for j:=1 to i-1 do
            if (length(a[j])=length(a[i])) then
               begin
                  for p:=1 to length(a[i]) do
                     if (a[i][p]<>a[j][p]) then
                        begin
                           if (not (less[ord(a[i][p])-97,ord(a[j][p])-97]))
                              then inc(last[ord(a[i][p])-97]);
                           if (not (more[ord(a[j][p])-97,ord(a[i][p])-97]))
                              then inc(next[ord(a[j][p])-97]);
                           less[ord(a[i][p])-97,ord(a[j][p])-97]:=true;
                           more[ord(a[j][p])-97,ord(a[i][p])-97]:=true;
                           break;
                        end;
               end;
      end;
   for i:=0 to 9 do
      for j:=0 to 9 do
         if (less[i,j]) and (more[i,j]) then
            begin
               writeln('No');
               readln;
               halt;
            end;
   for i:=1 to n do
      for j:=1 to n do
         if (i<>j) and (a[i]=a[j]) then
            begin
               writeln('No');
               readln;
               halt;
            end;
   for i:=1 to n do
      for j:=i-1 downto 1 do
         if (length(a[j])>length(a[i])) then
            begin
               writeln('No');
               readln;
               halt;
            end;
   f:=true;
   for i:=0 to 9 do
      if (nul[i]) and (last[i]=0) then
         begin
            f:=false;
            c[0]:=i;
            use[i]:=false;
            for j:=0 to 9 do
               if (more[i,j]) then dec(last[j]);
            break;
         end;
   if (f) then
      begin
         writeln('No');
         readln;
         halt;
      end;
   for kol:=1 to 9 do
      begin
         for i:=0 to 9 do
            if (use[i]) and (last[i]=0) then
               begin
                  c[kol]:=i;
                  use[i]:=false;
                  for j:=0 to 9 do
                     if (more[i,j]) then dec(last[j]);
                  break;
               end;
      end;
    {for i:=0 to 9 do write(c[i],' ');
    readln;
    halt;}
   for i:=0 to 9 do d[c[i]]:=i;
   writeln('Yes');
   for i:=0 to 8 do write(d[i],' ');
   writeln(d[9]);
   readln;
end.
