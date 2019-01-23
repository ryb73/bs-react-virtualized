let make:
    (~label: string=?, ~flexGrow: int=?, ~flexShrink: int=?, ~dataKey:
    string, ~width: int, 'a) =>
    ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps,
        ReasonReact.actionless);
