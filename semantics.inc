%macro var 3
  %define %1 %3
%endmacro

%macro fi 1
  %undef %1
%endmacro
