from django.urls import path,re_path
from django.conf.urls import url
from django.contrib.auth import views as auth_views

urlpatterns = [
path('change-password/',auth_views.PasswordChangeView.as_view()),

path('login/',
	auth_views.LogoutView.as_view(template_name='registration/login.html'),
		),


path('logout/', auth_views.LogoutView.as_view()),
path('password_change_done',auth_views.PasswordChangeDoneView.as_view()),

]



