[@bs.module "react-virtualized"] [@react.component]
external make:
    (   ~label: string=?, ~flexGrow: int=?, ~flexShrink: int=?, ~dataKey: string,
        ~width: int, unit
    ) => React.element = "Column";
