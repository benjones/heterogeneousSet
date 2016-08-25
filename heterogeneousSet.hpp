
#include <tuple>
#include <algorithm>


//TODO: ensure Ts are all different
template< template<typename> typename S, typename... Ts>
class HeterogeneousSet{
private:
  
  std::tuple< S<Ts>... >  sets;

  template<typename T, typename P>
  void removeIfSingle(P&& p){
	auto& set = std::get<S<T> >(sets);
	for(auto it = set.begin(); it != set.end(); ){
	  if(p(*it)){
		set.erase(it++);
	  } else {
		++it;
	  }
	}
  }

  
public:
  template<typename T>
  void insert(T t){
	std::get<S<T> >(sets).insert(t);
  }

  template<typename F>
  void foreach(F&& f){
	int ignore[] = {
	  (std::for_each( std::get< S<Ts> >(sets).begin(),
		  std::get< S<Ts> >(sets).end(),
		  f), 0)... };
	(void)ignore; //silence unused warning
  }

  template <typename P>
  void removeIf(P&& p){
	int ignore[] = {
	  ( removeIfSingle<Ts, P>( std::forward<P>(p) ), 0)...
	};
	(void)ignore;
  }
  
};

