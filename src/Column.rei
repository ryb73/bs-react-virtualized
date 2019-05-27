[@react.component]
let make:
    (   ~label: string=?, ~flexGrow: int=?, ~flexShrink: int=?,
        ~dataKey: string, ~width: int, unit
    ) => React.element;
